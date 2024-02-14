target_sources(menu PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/menu_functions.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/menu_functions.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/menu_item.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/menu_items.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/menu_items.hpp"
)

target_include_directories(menu PRIVATE "${PROJECT_SOURCE_DIR}/src")
