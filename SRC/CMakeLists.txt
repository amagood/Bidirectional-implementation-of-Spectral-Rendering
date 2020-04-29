cmake_minimum_required(VERSION 3.14)
project(TheNextWeekend)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,100000000")

include_directories(freeglut/include)  #for opengl freeglut
link_directories(freeglut/lib/x64) #for opengl freeglut
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin) #for opengl freeglut

add_executable(TheNextWeekend main.cpp aabb.h aarect.h box.h bvh.h camera.h constant_medium.h hittable.h hittable_list.h material.h moving_sphere.h perlin.h random.h ray.h sphere.h stb_image.h stb_image_write.h surface_texture.h svpng.h texture.h vec3.h triangle.h Color.h Color.cpp )

target_link_libraries(TheNextWeekend libopengl32.a libfreeglut.a -lglu32) #for opengl freeglut
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp -static-libgcc -static-libstdc++ -static -s -O3")