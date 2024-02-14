# file(GLOB SRC 
#     "src/*.cpp"
#     "src/*.hpp")

# target_sources(menu PRIVATE "${SRC}")
target_sources(menu PRIVATE 
    src/menu_functions.cpp
    src/menu_functions.hpp
    src/menu_item.hpp
    src/menu_items.cpp
    src/menu_items.hpp
)

target_include_directories(menu PRIVATE "${PROJECT_SOURCE_DIR}/src")
