set(TARGET_NAME "tests_plt")

file(GLOB_RECURSE TARGET_SRC  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${TARGET_NAME} ${TARGET_SRC})
target_link_libraries(${TARGET_NAME} PUBLIC gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(${TARGET_NAME})
