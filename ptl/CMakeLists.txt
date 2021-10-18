set(TARGET_NAME ptl)

file(GLOB_RECURSE TARGET_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*)

include_directories("include")

add_library(${TARGET_NAME} ${TARGET_HEADERS})

set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC OpenMP::OpenMP_CXX)
