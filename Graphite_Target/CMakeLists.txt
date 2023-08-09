cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(test)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)

file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)


add_executable(test.exe main.cc ${sources} ${headers})

target_link_libraries(test.exe ${Geant4_LIBRARIES})

add_custom_target(Simulation DEPENDS test.exe)
