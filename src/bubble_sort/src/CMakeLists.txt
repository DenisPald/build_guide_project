target_sources(bubble_sort PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/bubble_sort.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/bubble_sort.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/io_array.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/io_array.hpp"
)

target_include_directories(bubble_sort PRIVATE "${PROJECT_SOURCE_DIR}/src")
