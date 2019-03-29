cmake_minimum_required(VERSION 3.13)
project(OpenGL_trials)

set(CMAKE_CXX_STANDARD 14)

#--- Find GLUT
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)


#--- Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)


#--- GL includes
include_directories(
        "/usr/include/GL"
)


file(GLOB SOURCE_FILES
        *.cpp
        *.h
        *.hpp
        )

add_executable(main.cpp ${SOURCE_FILES})

target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLU_LIBRARIES} ${GL_LIBRARIES} ${CMAKE_DL_LIBS})
