# 2.0.0 release todo

The mechanical fixes are done (see [CHANGELOG.md](CHANGELOG.md)). What's left is mostly design work:
the refactors below are the interesting ones to do yourself. They're roughly in the order I'd do them,
since the later ones get easier once ownership is sorted out.

## 1. Resource ownership → RAII (the big one)
Most remaining lifetime bugs come from `dispose()` + a `disposed` flag + copyable handle types.
- [ ] Replace `dispose()` with destructors, and make GL/FreeType/GLFW wrapper types move-only: `= delete` copy, implement move ctor/assignment (the moved-from object holds 0/nullptr). Applies to `Shader, Mesh, Texture, Font, CharRenderable, TextRenderable(3D), UiRenderable, Renderable, ModelRenderable, Window, WindowIcon, Cursor, ImageData`. A small `GlHandle<Deleter>` or `std::unique_ptr` with a custom deleter can do most of the work.
  - Today, copying `Shader/Mesh/Texture` copies the raw GL id, and every copy can `glDelete*` it. By then the driver may have reused the id for something else.
  - `ModelRenderable(Model&, Shader override)` deletes the same program once per mesh.
  - `UiRenderable::dispose` / `TextRenderable::dispose` destroy meshes/textures/shaders the caller passed in and may still be using.
  - `Font` copies share the `FT_Face` and glyph textures.
  - `WindowIcon`: `Window::get_icon()` returns a shallow copy that dangles once the user disposes theirs. `examples/cubes.cpp` disposes right after `set_icon`, which only works because GLFW copies the pixels.
  - `Window` stores `this` in GLFW and in its static window registry, so a copied or moved `Window` leaves stale pointers.
- [ ] Decide who owns what between `Renderer` and renderables. `Renderer` stores raw pointers but `Renderer::dispose()` disposes them, and `add(ModelRenderable&)` stores pointers into another object's `std::map`. Either the renderer *references* (the caller owns the objects) or it owns them (`shared_ptr`/handles). Pick one and document it.
- [ ] `VertexBuffer/IndexBuffer` keep a raw pointer plus a `heap` flag, and `Mesh` frees the memory, so two meshes built from one buffer double-free. Use `std::vector` (owning) or `std::span` (non-owning).
- [ ] Remove the `onyx_add_malloc` registry (it now frees with the right types, but everything still lives until `cleanup()`). `Model::load_obj` returning `Model&` into the registry should return by value.
- [ ] Remove `Disposable`. It has no virtual destructor, and RAII makes it pointless.
- [ ] Remove two-phase init and the "default constructor is UB" docs. Replace `bool* result` out-params with factories returning `std::optional` / `std::expected` (C++23), or exceptions. `TextRenderable::get_font()` still dereferences a null font on an empty object; with this change it can't happen.
- [ ] Also sanitizes cleanly afterwards: `cmake --preset asan && cmake --build --preset asan`, then run every example.

## 2. Input
- [ ] Fix how key states are interpreted. Each state is the last raw GLFW action, so `is_key_pressed` is true for about 0.5 s (the OS repeat delay), then false while the key is still held. `Repeat` depends on OS settings, and only one key repeats at a time. Derive per-frame `down` / `pressed_this_frame` / `released_this_frame` from PRESS/RELEASE, and treat REPEAT as a text-input event only. Collapse the 4-valued `KeyState` (`Untouched`/`Release` both mean up) and make it an `enum class`. This is a good place for unit tests: feed in fake events and assert the states.
- [ ] `is_key_down` with a cooldown silently turns into a throttled press. Split it into a separate API.
- [ ] Several `InputHandler`s and `Window::close()` each call `glfwPollEvents`, so handlers after the first never see taps. Poll once per frame in one place.
- [ ] First-mouse handling: the camera ignores rotation on frames 1–4 (`camera.cpp`, look for the TODOs). Instead, reset the mouse delta when the cursor is captured or first moves. The same nested `if` means `rotate/pitch/yaw` skip the zero-delta early return when no window is linked.
- [ ] HiDPI: the cursor is in screen coordinates but the ortho UI projection uses framebuffer pixels. Scale by `framebuffer / window` size (or give the UI projection window coordinates).
- [ ] Linux lock keys open an X display on every query and always return false on Wayland. Consider tracking lock state from GLFW key mods (`GLFW_MOD_CAPS_LOCK` with `GLFW_LOCK_KEY_MODS`) on all platforms and dropping the OS-specific code.
- [ ] Callbacks are raw function pointers with no user data (which is why the user-pointer map exists). Switch to `std::function`.

## 3. Rendering architecture & performance
- [ ] Text rendering (no VAO/VBO per character). Today there are 128 textures per font, a VAO + VBO + texture per character, N draw calls per string, and `set_text` recreates 2N GL objects, so FPS counters churn every frame. Plan:
  - a shelf-packed glyph atlas: one R8 texture, with UVs, bearing and advance precomputed, and the `FT_Face` freed after load
  - one dynamic VBO per text object (or instanced quads), so one draw call per string
  - add kerning and `\n` support while you're in the layout code
  - `Font` could store glyphs in `std::array<Glyph,128>` or a codepoint hash map instead of `std::map<char,…>`
- [ ] Deduplicate `TextRenderable` and `TextRenderable3D` (about 90% identical) into a shared `TextLayout`/`TextMesh` plus a transform. The 4 near-identical constructors per class can delegate.
- [ ] Share one program per builtin shader. Today every `Renderable::colored_cube` or `TextRenderable` compiles its own, so 1000 cubes means 1000 programs. Color becomes a per-renderable uniform.
- [ ] Cache uniform locations. Every `set_*` calls `glGetUniformLocation`, and `Renderable::render` does 5 lookups per draw.
- [ ] Put lighting and fog in a std140 UBO instead of pushing uniforms into every shader on add/set/refresh. That removes the 5× duplicated block in `renderer.cpp` and the `refresh_*()` API.
- [ ] Add instancing.
- [ ] Avoid redundant bind/unbind per draw, and sort draws by shader and texture.
- [ ] Compute the normal matrix on the CPU. Shaders do `mat3(transpose(u_inverse_model))` per vertex.
- [ ] Move the builtin GLSL out of the 965-line `builtin_shaders.hpp` into `shaders/*.glsl` with a shared fog/lighting include (the fog code is copy-pasted about 13×). Embed it at build time (a CMake script generating a header), and run `glslangValidator` in CI.
- [ ] Lighting: per-pixel instead of per-vertex for the `pn_*` shaders, and sRGB (`GL_SRGB8_ALPHA8` + `GL_FRAMEBUFFER_SRGB`) so lighting math runs in linear space.
- [ ] `Lighting()` leaves the direction as a zero vector, which gives NaN in the shader. Give it a sane default.
- [ ] Textured cylinders: the last side quad maps u from about (n-1)/n back to 0, which needs a duplicated seam column. The circle bottom face has the same winding as the top, which matters with back-face culling.
- [ ] `Texture(ImageData)` rejects grayscale images. Map channels or swizzle.
- [ ] Thread safety: the mutexes around GL state do nothing (the context belongs to one thread), and several "thread-safe" paths aren't (`onyx_get_ft` returns after unlocking, the `ErrorHandler` vector isn't synchronized). Remove them, and document that Onyx is single-threaded except for clearly marked functions. Fix the README claim to match.

## 4. API design
- [ ] Math: replace the hand-written wrappers (about 8k lines, 16 vector + 9 matrix classes, empty `Vec`/`Mat` base classes, `DVec : Vec`) with `using Vec3 = glm::vec3` etc. plus a small helpers header (color presets, `remap`, `rand`). If you keep wrappers, template them (`Vec<N, T>`), and add `/`, component-wise `*`, `scalar * vec` and writable `[]`. (A worker added the `Mat3x2*Vec3→Vec2`, `Mat4x2*Vec4→Vec2`, `Mat4x3*Vec4→Vec3` overloads while fixing the dimensions; drop them if they don't fit your design.)
- [ ] Replace the `link_*` methods with an environment/context class. `Window` makes `InputHandler`, `Camera` and `Renderer` friends that reach into its privates.
- [ ] Error reporting: the library prints to `std::cout` directly (`onyx_glerr`, `ErrorHandler`). Route it through a user-settable sink.
- [ ] Deduplicate `Window::init` vs `init(share)` (about 75 identical lines), the two `onyx::init` overloads, and `resources()`/`res()`.
- [ ] Naming: `orthographic(float,float)` vs `perspective(float,int,int)`, getters that return `Mesh/Shader/Texture` by value, and `get_shader()` existing only on 3D text and returning a raw pointer. `set_mat2`/`set_mat2x2` (and 3/4) are duplicate pairs because `Mat2` is an alias; keep one spelling.
- [ ] `Renderer::get_renderable(name)` throws `std::out_of_range` for unknown names. Return a pointer or optional.
- [ ] Window methods call GLFW with a null window before `init()`. `Window::set_cursor` doesn't update the stored cursor, so `get_cursor()` always returns the arrow. `Renderer::set_vsync` before any window exists raises a GLFW "no context" error (the value is still applied at window init).
- [ ] Windows: `sleep` has about 15.6 ms granularity by default, so the FPS limiter can overshoot. Consider `timeBeginPeriod(1)` (links winmm).

## 5. Build, packaging, tests
- [ ] `install()` + `install(EXPORT)` + `OnyxConfig.cmake` / `OnyxConfigVersion.cmake` (`CMakePackageConfigHelpers`), so users can `find_package(Onyx)`. The `Onyx::onyx` alias already exists for `add_subdirectory`/FetchContent users. `onyx_glad` has to be exported or installed alongside.
- [ ] Shared library support: `BUILD_SHARED_LIBS` plus an export macro (`GenerateExportHeader`) or `WINDOWS_EXPORT_ALL_SYMBOLS`.
- [ ] Unit tests (Catch2 or doctest via FetchContent, run with `ctest`, behind an `ONYX_BUILD_TESTS` option) for non-GL code: math (it would have caught the recursion, swizzle and matrix bugs), the input state machine, string/key maps, font layout metrics, file utils. Add them to CI.
- [ ] Headless smoke test in CI: run each example for N frames under Xvfb with Mesa llvmpipe. The examples would need an `--frames N` flag.
- [ ] clang-tidy (`bugprone-*`, `modernize-*`, `performance-*`) and a clang-format check in CI. Add `.clang-format` + `.editorconfig`, then format everything once in a single commit (tabs and spaces are mixed today).
- [ ] Check the first CI run. It's written but not yet run on GitHub: MSVC, macOS and Linux have only been compile-checked locally (MSVC) or not at all (macOS/Linux).
- [ ] Consider tinyobjloader instead of the unmaintained OBJ_Loader.h.
- [ ] Before tagging, decide on `ONYX_VERSION_SUFFIX` in CMakeLists.txt (currently `"alpha"`).

## 6. Examples & docs
- [ ] Redo the README and tutorials:
  - a screenshot or gif at the top, a one-paragraph pitch and a feature list
  - a quick start: a FetchContent snippet plus a 30-line example
  - build instructions inline, not only in the wiki
  - a platforms/compilers table and a CI badge
  - an architecture overview (Window → InputHandler / Renderer → Renderable/Shader/Mesh), and the design decisions you made
  - drop "I am just a high school student", "if you want to make a crazy game, look elsewhere", "pre-compiled binaries ... not guaranteed to work" and the thread-safety claim
  - update the latest-release link
  - update the wiki tutorials to the 2.0 API (renamed and removed functions are in the CHANGELOG)
- [ ] Write a migration guide from 1.x to 2.0. The CHANGELOG's "Breaking changes" section is a starting point.
- [ ] Add an example per headline feature (a minimal hello-window, text/UI, lighting + fog, model loading, input/gamepad), with a screenshot of each for the README.
- [ ] `bouncing_ball`: `ball.scale(0.001f)` works around the sphere model's huge units. Rescale `sphere.obj`.
- [ ] Generate API docs with Doxygen (the headers already have `@brief`) and publish them to GitHub Pages from CI.

## 7. Repo
- [ ] Move `tutorial_images/` (33 MB) to the wiki repo, and `logo.psd` out of the repo or to `docs/assets/`. The pack is about 118 MB. Consider a history rewrite (`git filter-repo`) before the release so clones are fast. That's destructive: coordinate it with any forks and clones.
- [ ] Delete the stale local `master` branch (from 2024, before the CMake move).
- [ ] Move what's left in this file to GitHub issues or a project board, and drop `todo.md` from the default branch.
- [ ] Release: merge `dev` into `release`, tag `v2.0.0`, and write a GitHub release with notes from the CHANGELOG and screenshots. Optionally add a CI job that attaches packaged binaries (`include(CPack)` once install rules exist).
