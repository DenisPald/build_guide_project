#include "io_array.hpp"

#include <iostream>

void IOArray::print_array(int arr[], const int &n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}
