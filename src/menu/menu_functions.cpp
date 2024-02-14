#include "menu_functions.hpp"
#include "menu_item.hpp"
#include "menu_items.hpp"
#include <iostream>
#include <random>

const Menu::MenuItem* Menu::show_menu(const Menu::MenuItem* self){
    std::cout << "Обучайка: " << self->title << std::endl;

    for (int i = 1; i < self->childen_count; i++){
        std::cout << i << " - " << self->childen[i]->title << std::endl;
    }

    if (self->childen_count) std::cout << 0 << " - " << self->childen[0]->title << std::endl;

    std::cout << "> ";
    int choise;
    std::cin >> choise;
    std::cout << std::endl;

    if (choise > self->childen_count) return self;

    return self->childen[choise]; 
}

const Menu::MenuItem* Menu::exit_func(const Menu::MenuItem* self){
    std::cout << "Завершение программы";
    std::exit(0);
    return self;
}

const Menu::MenuItem* Menu::go_back_func(const Menu::MenuItem* self){
    std::cout << self->title << std::endl << std::endl;
    return self->parent;
}

const Menu::MenuItem* Menu::learn_addition(const MenuItem * self){
    std::cout << "Обучайка: " << self->title << std::endl;
    std::cout << "Какой нибудь текст про сложение" << std::endl;
    std::cout << "А теперь проверим полученные знания" << std::endl;

    std::mt19937 mt(time(nullptr));
    int x = mt() % 100;
    int y = mt() % 100;

    std::cout << "Сколько будет " << x << " + " << y << " ?" << std::endl;
    std::cout << "> ";
    int user_input;
    std::cin >> user_input;

    if (user_input == x+y) {
        std::cout << "Верно!" << std::endl;
    } else {
        std::cout << "Не верно! Попробуй еще раз" << std::endl;
    }
    std::cout << std::endl;

    return self->parent;
};
