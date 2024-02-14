#include "menu_functions.hpp"
#include "menu_item.hpp"
#include "menu_items.hpp"
#include <clocale>
#include <iostream>

int main(){
    std::setlocale(LC_ALL, "");
    const Menu::MenuItem* current = &Menu::main_item;

    while(true){
        current = current->func(current);
    }
}
