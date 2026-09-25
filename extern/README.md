# Vendored dependencies

Small single-header and generated libraries are checked in here. Everything else
(GLFW, FreeType, glm) is pulled in by CMake `FetchContent` or found with
`find_package`; see [CMakeLists.txt](../CMakeLists.txt).

| Library | Version | License | Path | Used by |
| --- | --- | --- | --- | --- |
| [glad](https://github.com/Dav1dde/glad) | generator 0.1.36, OpenGL 4.1 **core**, no extensions | MIT (generator); generated code is public domain / Apache 2.0 per Khronos registry | `glad/` | public (exposed through `window.hpp`) |
| [Khronos `khrplatform.h`](https://github.com/KhronosGroup/EGL-Registry) | registry `main` at generation time | MIT-style Khronos license | `glad/include/KHR/` | glad |
| [stb_image](https://github.com/nothings/stb) | 2.28 (unmodified) | MIT or public domain | `stb/` | private (`src/stb_image.cpp` compiles the implementation) |
| [OBJ-Loader](https://github.com/Bly7/OBJ-Loader) | upstream `master` | MIT | `obj_loader/` | private (`src/model.cpp`) |

## Regenerating glad

```sh
python -m pip install glad==0.1.36
python -m glad --profile=core --api="gl=4.1" --generator=c --spec=gl --extensions="" --out-path=glad_out
```

Copy `glad_out/include/*` to `extern/glad/include/` and `glad_out/src/glad.c` to
`extern/glad/src/`. If the download of `gl.xml` fails, place the
[registry's `gl.xml`](https://github.com/KhronosGroup/OpenGL-Registry/blob/main/xml/gl.xml)
and `khrplatform.h` in the working directory first; glad uses local copies when present.
