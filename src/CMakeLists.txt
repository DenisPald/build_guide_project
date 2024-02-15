cmake_minimum_required(VERSION 3.27)

project(build_guide_project)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(bubble_sort)
add_subdirectory(menu)
add_subdirectory(shell_sort)
add_subdirectory(unit_test_example)

set(CMAKE_SUPPRESS_REGENERATION true)

