cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(Graphite_Target)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)

file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)


add_executable(Graphite_Target main.cc ${sources} ${headers})

target_link_libraries(Graphite_Target ${Geant4_LIBRARIES})

add_custom_target(Simulation DEPENDS Graphite_Target)
