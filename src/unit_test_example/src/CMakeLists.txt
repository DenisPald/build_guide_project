target_sources(bubble_sort_lib INTERFACE 
    "${CMAKE_CURRENT_SOURCE_DIR}/bubble_sort.hpp"
    PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/bubble_sort.cpp"
)

target_include_directories(bubble_sort_lib INTERFACE "${PROJECT_SOURCE_DIR}/src")
