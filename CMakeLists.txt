cmake_minimum_required(VERSION 2.8)
#g++ opengl.cpp -lglut -lGLU -lGL -lGLU -o example
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

project(hello_opengl)
find_package( OpenGL REQUIRED )
find_package(glfw3 REQUIRED)
message(STATUS "GLFW3:" OpenGL_VERSION)
add_executable(${PROJECT_NAME}  opengl.cpp)
set(TARGET_LIB
"/usr/lib/x86_64-linux-gnu/libGL.so"
"/usr/lib/x86_64-linux-gnu/libGLU.so"
"/usr/lib/x86_64-linux-gnu/libglut.so"
)
target_link_libraries(${PROJECT_NAME}
        ${TARGET_LIB}
    )
