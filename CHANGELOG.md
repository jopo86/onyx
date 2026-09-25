# Changelog

All notable changes to Onyx are documented here. The format is based on
[Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and the project follows
[Semantic Versioning](https://semver.org/). Releases before 2.0.0 are described in the
[GitHub release notes](https://github.com/jopo86/onyx/releases).

## [2.0.0] - Unreleased

### Breaking changes
- Naming now follows snake_case (Rust-style) conventions throughout the API.
- Headers moved to `include/onyx/*.hpp`; include them as `<onyx/window.hpp>` etc.
- Onyx no longer ships resources. Set a resource path with `onyx::set_resource_path()`.
- Removed APIs that were deprecated in 1.x:
  - the point-based `Renderable::colored_triangle`, `vertex_colored_triangle`, `textured_triangle`, `colored_quad`, `vertex_colored_quad`, `textured_quad` overloads and `Mesh::triangle`, `quad`, `rect_prism` overloads
  - `onyx::set_user_ptr(void*)`, `onyx::get_user_ptr()`
  - `InputHandler::refresh_gamepads()`, `Gamepad::is_button_pressed()`
  - `TextRenderable::dimensions()`, `TextRenderable3D::dimensions()`
- `Renderer::clear_text_renderables3_d()` renamed to `clear_text_renderables_3d()`.
- `Renderer::get_camera()`, `get_lighting()` and `get_fog()` return `const T*` (`nullptr` when unset) instead of references.
- `UiRenderable` constructors take `int z_index` (was `u32`), matching `set_z_index`.
- Non-square matrix wrappers follow glm's convention (`MatCxR` = C columns × R rows). Products and matrix × vector operators return the mathematically correct types (e.g. `Mat2x3 * Mat3x2` is a `Mat3`), and `to_string()` prints row by row.
- The matrix setters' `normalize` parameter is now named `transpose`, which is what it always did.
- `usize` is `std::size_t` (was `unsigned long`, which is 32-bit on Windows).
- `font.hpp`, `core.hpp` and other public headers no longer include `<iostream>` or FreeType.
- `prelude.hpp` no longer injects `using` declarations into the global namespace; add `using namespace onyx::prelude;` instead.
- The version is generated from CMake (`<onyx/version.hpp>`); `ONYX_PRE_RELEASE_NUM` is replaced by `ONYX_VERSION_SUFFIX` / `ONYX_VERSION_STRING`.

### Added
- `<onyx/prelude.hpp>`, a single include for the commonly used parts of the library.
- `Font::get_glyph(char)`, which falls back to `'?'` for characters the font doesn't have.
- The `Onyx::onyx` CMake alias target, and the `ONYX_WARNINGS_AS_ERRORS` and `ONYX_SANITIZE` (ASan + UBSan) options.
- `CMakePresets.json` with `debug`, `release`, `asan` and `ci` presets.
- A GitHub Actions build matrix (Windows MSVC/MinGW, Ubuntu GCC/Clang, macOS Clang).
- A camera-mode toggle (Tab) in the bouncing ball example.

### Changed
- Dependencies come from CMake `FetchContent`, trying `find_package` first: GLFW 3.4, FreeType 2.13.3 and glm 1.0.1. glm is no longer vendored.
- glad is regenerated for the OpenGL 4.1 **core** profile (was compatibility) and built as its own target. The vendored libraries are documented in `extern/README.md`.
- Sources are listed explicitly in CMake, and examples build by default only when Onyx is the top-level project.
- The library builds warning-free with `-Wall -Wextra -Wpedantic` and `/W4`. The MSVC-only `#pragma warning(disable ...)` lines are removed.
- `rand()` uses `<random>` (unbiased, per-thread engine) instead of `::rand() %`.
- The FPS limiter sleeps instead of busy-waiting at 100% CPU.
- Vsync follows `Renderer::set_vsync()` instead of being forced on.
- `ErrorHandler` keeps only the most recent `max_history` (256) warnings and errors.
- Textures always upload as RGBA and use mipmapped minification filters.
- `glValidateProgram` failures are reported as warnings instead of destroying the shader.
- Camera pitch clamp docs now match the code (88°). `set_pitch_clamp` limits the clamp to 89.9°.
- The old test programs are now examples under `examples/`, with their resources in `examples/resources/`.

### Fixed
- **Crashes and undefined behavior**
  - `onyx::math::abs`, `sqrt`, `pow` and the `double` trig and rounding functions called themselves forever (stack overflow).
  - Pressing the last key (`Menu`), mouse button 8, or D-pad left wrote past the end of the input arrays. Key and button queries are now bounds-checked.
  - Gamepad and monitor callbacks used dangling `this` pointers.
  - Reinitializing after `onyx::terminate()` used freed monitor data. This is the likely cause of the reinit failures on Linux.
  - `get_user_ptr` could deadlock permanently when the key was missing. All mutexes now use RAII locks.
  - The allocation registry deleted `void*` (undefined behavior, leaked `std::string`/`std::vector` contents). It now frees each allocation with its real type.
  - `Font` called `FT_Done_Face` on an uninitialized face when loading failed.
  - Text containing characters outside the loaded glyph set (non-ASCII, `\t`) threw `std::out_of_range`.
  - `WindowIcon::load` freed uninitialized pointers on partial failure, and left image flipping disabled for later texture loads.
  - Double frees in `ImageData::dispose`.
  - A null deref in `get_clipboard_string`, and an overflow in `onyx::sleep` for waits over 2.1 s.
  - Undefined behavior with an FPS limit of 0.
  - Null derefs in `Renderer::render` (UI camera with no camera set), `TextRenderable::set_text` on an empty object, and `ModelRenderable` getters on an empty model.
  - NaN projections when the window is minimized, and NaN camera vectors from `look_at` straight up or with pitch clamps ≥ 90°.
  - The macOS caps-lock query didn't compile, and it reported whether the key was held rather than toggled.
  - Uploading 1- and 2-channel textures read past the image buffer.
- **Math**
  - `xy()`, `yx()` and `yy()` returned `(x, x)` for every 2D vector type.
  - Non-square matrix products and matrix × vector products silently truncated or padded results.
  - `normalize()` of a zero vector and `remap()` with a zero-width range produced NaN.
- **Input**
  - `str_to_key` / `str_to_mouse_button` compared pointers instead of strings and never matched runtime strings.
  - `char_to_key` now accepts lowercase letters.
  - Setting a key cooldown twice made it count down twice as fast.
  - Gamepad disconnects were never handled.
  - `GamepadButton::DpadRight` had the same value as `DpadUp`.
  - `is_focused()` and `is_visible()` returned stale values.
  - The cursor y-flip used framebuffer instead of window coordinates.
- **Rendering**
  - Textured objects rendered black with lighting off and fog on (a shader fall-through), and fog dropped alpha.
  - Fog divided by zero when `start == end` (including the default `Fog()`).
  - The two XYZ-to-RGB shaders now both color by model-space position (one used world space).
  - `Renderable::reset_transform` left a stale inverse model matrix. Text and UI `reset_transform` dropped z and left scaled dimensions.
  - Cylinders had a seam at the wrong vertex, and circle/cylinder vertex and index counts could disagree.
  - OBJ models with Windows paths failed to find their textures. Unnamed or duplicate OBJ meshes were silently dropped.
  - `glLineWidth` values other than 1 raised GL errors on macOS core contexts.
  - Shader binary load/save didn't validate input, and `load_source` compiled before checking the files were read.
  - Font string width and height measurements ignored bearings.
  - `GL_UNPACK_ALIGNMENT` leaked from font loading into later texture uploads.
  - `gl_check_error` always returned 0.
- **Camera**
  - `set_pitch` treated its argument as a delta.
  - Orthographic cameras snapped 90° on the first rotation.
  - The default `Camera()` produced a NaN view matrix.
- **Misc**
  - Ambient lighting didn't work.
  - Warnings about the camera or input handler not being updated were emitted every frame.
  - The bouncing ball example used z-up normals on a y-up surface (wrong lighting and bounces) and read mouse input a frame late.
  - The window example's opacity keys barely changed opacity.
  - Stale and incorrect documentation across the headers.

### Removed
- The vendored glm and a stray copy of FreeType's `ft2build.h`.
- The `examples/tmp.cpp` scratch example.
