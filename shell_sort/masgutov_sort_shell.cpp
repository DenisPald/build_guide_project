#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

void shell_sort(int arr[], const int size, const int intervals[],
                const int interval_size) {
    for (int i = 0; i < interval_size; i++) {
        int s = intervals[i];
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && arr[j] > arr[j + s]; j -= s) {
                int temp = arr[j];
                arr[j] = arr[j + s];
                arr[j + s] = temp;
            }
        }
    }
}

int main() {
    int smooth[] = {1,    2,    3,    4,    6,    8,    9,    12,   16,   18,
                    24,   27,   32,   36,   48,   54,   64,   72,   81,   96,
                    108,  128,  144,  162,  192,  216,  243,  256,  288,  324,
                    384,  432,  486,  512,  576,  648,  729,  768,  864,  972,
                    1024, 1152, 1296, 1458, 1536, 1728, 1944, 2048, 2187, 2304,
                    2592, 2916, 3072, 3456, 3888
    };
    int smooth_size = sizeof(smooth) / sizeof(smooth[0]);

    std::mt19937 mt(std::time(nullptr));
    for (int N = 3; N < 7; N++) {
        int arr_size = std::pow(10, N);
        int arr[arr_size];
        int arr_copy[arr_size];

        for (int i = 0; i < arr_size; i++) {
            int cur = mt() % 1000;
            arr[i] = cur;
            arr_copy[i] = cur;
        }

        auto start_shell = std::chrono::steady_clock::now();
        shell_sort(arr, arr_size, smooth, smooth_size);
        auto end_shell = std::chrono::steady_clock::now();

        auto start_standart = std::chrono::steady_clock::now();
        std::sort(arr_copy, arr_copy + arr_size);
        auto end_standart = std::chrono::steady_clock::now();

        std::cout << "N=" << N << "\n";
        std::cout << "Мое время: " << (end_shell - start_shell).count() << "\n";
        std::cout << "Стандартное время: "
                  << (end_standart - start_standart).count() << "\n";
        std::cout << "Отношение моего времени к стандартному: "
                  << double((end_shell - start_shell).count()) /
                         double((end_standart - start_standart).count())
                  << "\n";
    }
}
