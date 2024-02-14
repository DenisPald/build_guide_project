#pragma once

#include <cstddef>
namespace Menu {
    struct MenuItem{
        const char* const title;
        const MenuItem* (*func)(const MenuItem*);
        const MenuItem* parent;
        
        const MenuItem* const *childen;
        const std::size_t childen_count;
    };
}
