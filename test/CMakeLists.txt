file(GLOB TEST_SOURCES "*.cpp")

foreach(TEST_FILE IN LISTS TEST_SOURCES)
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE
        lib
        Catch2::Catch2WithMain
    )

    catch_discover_tests(${TEST_NAME} ADD_TAGS_AS_LABELS)
endforeach()