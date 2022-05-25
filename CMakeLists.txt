cmake_minimum_required(VERSION 3.1)
project(DummyLib)

###############################################################################
## Enable C++ language.
###############################################################################
enable_language(CXX)

###############################################################################
## Use C++ 17.
###############################################################################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

###############################################################################
## Output directories.
###############################################################################
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

###############################################################################
## Various flags.
###############################################################################
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckIncludeFiles)
include(ExternalProject)

###############################################################################
## Enable all warnings and warnings as errors.
###############################################################################
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # using Clang
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-missing-braces -Wno-long-long \
                       -pedantic")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-long-long -pedantic")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /WX")
endif()

###############################################################################
## Target definitions.
###############################################################################
file(GLOB_RECURSE PROJECT_SRC_LST ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(jlib SHARED ${PROJECT_SRC_LST})
set_target_properties(jlib PROPERTIES PUBLIC_HEADER include/jlib.hpp)
target_compile_options(jlib PUBLIC $<$<CONFIG:DEBUG>:-DPROJECT_NAME_DEBUG>)
target_include_directories(jlib PUBLIC ${PROJECT_SOURCE_DIR}/src/ ${PROJECT_SOURCE_DIR}/include/)
include(GNUInstallDirs)
install(TARGETS jlib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

###############################################################################
## Unit test target.
###############################################################################
option(BUILD_TESTS "Build unit tests" ON)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
