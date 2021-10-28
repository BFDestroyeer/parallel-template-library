set(TARGET_NAME "tests_plt")

file(GLOB_RECURSE TARGET_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${TARGET_NAME} ${TARGET_SRC})

target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/ptl/include)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
    target_compile_options (${TARGET_NAME} PUBLIC -EHsc)
endif()

target_link_libraries(${TARGET_NAME} PUBLIC gtest gtest_main PUBLIC OpenMP::OpenMP_CXX)

include(GoogleTest)
gtest_discover_tests(${TARGET_NAME})
