#include <iostream>

#include "bubble_sort.hpp"
#include "io_array.hpp"

int main() {
    int arr[] = {8,2,3};
    const int arr_size = std::size(arr);
    BubbleSort::sort(arr, arr_size);

    std::cout << "Result of sorting: ";
    IOArray::print_array(arr, arr_size);
}
