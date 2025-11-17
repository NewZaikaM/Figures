add_library(lib STATIC)

set_target_properties(lib PROPERTIES OUTPUT_NAME "lib")

file(GLOB_RECURSE LIB_SOURCES
    "*.cpp"
    "*.h"
)
list(FILTER LIB_SOURCES EXCLUDE REGEX "application\\.cpp$")

target_sources(
    lib
    PRIVATE
        ${LIB_SOURCES}
)


add_executable(application)
set_target_properties(application PROPERTIES OUTPUT_NAME "app")

target_link_libraries(
    application
    PRIVATE
        lib
)

target_sources(
    application
    PRIVATE
        "application.cpp"
)