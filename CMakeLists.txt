cmake_minimum_required (VERSION 3.24)

project ("Figures" VERSION 1.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CMakePrintHelpers)



cmake_print_variables(CMAKE_MODULE_PATH)
cmake_print_variables(CMAKE_PREFIX_PATH)
cmake_print_variables(CMAKE_INSTALL_PREFIX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(FindOrFetch)



include(CTest)

if(BUILD_TESTING)
  find_or_fetch_library(
    NAME           Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.9.1
  )
  include(Catch)
endif()

add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include_directories("src")
add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()
