target_sources(bubble_sort PRIVATE 
    src/bubble_sort.cpp
    src/bubble_sort.hpp
    src/io_array.cpp
    src/io_array.hpp
)

target_include_directories(bubble_sort PRIVATE "${PROJECT_SOURCE_DIR}/src")
