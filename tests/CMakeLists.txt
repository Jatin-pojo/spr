# cmake_minimum_required(VERSION 3.0)
# project(project_name_test)

# Prepare "Catch" library for other executables.
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

include(CTest)

# Remove project's main.cpp.
list(REMOVE_ITEM PROJECT_SRC_LST ${PROJECT_SRC_DIR}/src/main.cpp)

# Make test executable.
file(GLOB_RECURSE TEST_SOURCES ${PROJECT_SRC_LST} ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(Test1 ${TEST_SOURCES})
target_link_libraries(Test1 Catch jlib)

add_test(Test1 Test1 )
