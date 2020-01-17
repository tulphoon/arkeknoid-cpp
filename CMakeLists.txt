cmake_minimum_required(VERSION 3.15)
project(arkeknoid_cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

add_executable(arkeknoid_cpp src/main.cpp src/Game.cpp src/Game.h src/GameObject.cpp src/GameObject.h src/Vec2D.cpp src/Vec2D.h src/Player.cpp src/Player.h src/Ball.cpp src/Ball.h src/Text.cpp src/Text.h)

target_link_libraries(arkeknoid_cpp ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
