#include "menu_items.hpp"
#include <iostream>
#include "menu_functions.hpp"
#include "menu_item.hpp"

const Menu::MenuItem Menu::get_go_back_item(const Menu::MenuItem* self){
    Menu::MenuItem item = {"Назад", Menu::go_back_func, self->parent, nullptr, 0};
    return item;
}
const Menu::MenuItem Menu::exit_item = {"Выход", Menu::exit_func, nullptr, nullptr, 0};

const Menu::MenuItem Menu::arithmetic_addition = {"Хочу учить сложение", Menu::learn_addition, &Menu::arithmetic, nullptr, 0};
const Menu::MenuItem Menu::arithmetic_substraction = {"Хочу учить вычитание", Menu::go_back_func, &Menu::arithmetic, nullptr, 0};
const Menu::MenuItem Menu::arithmetic_multiplication = {"Хочу учить умножение", Menu::go_back_func, &Menu::arithmetic, nullptr, 0};
const Menu::MenuItem Menu::arithmetic_division = {"Хочу учить деление", Menu::go_back_func, &Menu::arithmetic, nullptr, 0};
namespace{
    const Menu::MenuItem go_back = Menu::get_go_back_item(&Menu::arithmetic);
    const Menu::MenuItem* const arithmetic_childrens[] = {
        &go_back,
        &Menu::arithmetic_addition,
        &Menu::arithmetic_division,
        &Menu::arithmetic_multiplication,
        &Menu::arithmetic_substraction
    };
    const short arithmetic_childrens_size = sizeof(arithmetic_childrens)/sizeof(arithmetic_childrens[0]);
}

const Menu::MenuItem Menu::arithmetic = {"Хочу учить арифметику", Menu::show_menu, &Menu::want_to_learn_item, arithmetic_childrens, arithmetic_childrens_size};
const Menu::MenuItem Menu::geometry = {"Хочу учить геометрию", Menu::go_back_func, &Menu::want_to_learn_item, nullptr, 0};
const Menu::MenuItem Menu::matanalysis = {"Хочу учить матанализ", Menu::go_back_func, &Menu::want_to_learn_item, nullptr, 0};
namespace{
    const Menu::MenuItem* const want_to_learn_childrens[] = {&Menu::exit_item, &Menu::arithmetic, &Menu::geometry, &Menu::matanalysis};
    const short want_to_learn_childrens_size = sizeof(want_to_learn_childrens)/sizeof(want_to_learn_childrens[0]);
}
const Menu::MenuItem Menu::want_to_learn_item = {"Хочу изучать математику", Menu::show_menu, &Menu::main_item, want_to_learn_childrens, want_to_learn_childrens_size};

namespace{
    const Menu::MenuItem* const main_menu_childrens[] = {&Menu::exit_item, &Menu::want_to_learn_item};
    const short main_menu_childrens_size = sizeof(main_menu_childrens)/sizeof(main_menu_childrens[0]);
}
const Menu::MenuItem Menu::main_item = {"Главное меню", Menu::show_menu, nullptr, main_menu_childrens, main_menu_childrens_size};

