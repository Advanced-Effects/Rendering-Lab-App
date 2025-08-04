# thirdparty/skia

- You **NEED** to **run** `git submodule init` and `git submodule update`. When you do that, you will see a new folder `skia/` is created under this directory. **IF NOT, YOU WILL NOT GET SKIA**. If you can't do that, make sure you are using `git clone`. **YOU CAN NOT DOWNLOAD THIS REPOSITORY AS A ZIP FROM GITHUB**
- That's the source code for Skia, which is the library we use to draw 2D shapes.
- The code for including Skia commences at `thirdparty/skia/CMakeLists.txt`
- We add it as an `ExternalProject` and generate a `libskia.friction.so` file, which we then link to the main executable in `app/` using `target_link_libraries(skia.friction)`
- We then bind Skia to the OpenGL window in `src/ISkiaGLWindow.h`
- If you see calls like `include(SomethingHere)`, that means we are including a script from `buildscripts/skia/SomethingHere.cmake`.
