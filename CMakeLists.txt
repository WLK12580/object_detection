cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)


project(test)
 
find_package(glfw3 REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED )
include_directories( ${OPENGL_INCLUDE_DIRS} )
include_directories( ${GLFW3_INCLUDE_DIRS} )
include_directories( ${GLUT_INCLUDE_DIRS} )
aux_source_directory(. DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS})
 
target_link_libraries(${PROJECT_NAME}  ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
