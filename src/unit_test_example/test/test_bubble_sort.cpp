#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "bubble_sort.hpp"

TEST(BubbleSortTest, PositiveInput) {
    int actual[10] = {1, 4, 2, 3, 5, 6, 9, 8, 7, 10};
    BubbleSort::sort(actual, 10);
    int expected[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(expected[i], actual[i])
            << "Массив ожидаемый и отсортировнный отличаются в элементе с "
               "индексом "
            << i;
    }
}

TEST(BubbleSortTest, NegativeInput) {
    int actual[5] = {-1, -3, -4, -2, 0};
    BubbleSort::sort(actual, 5);
    int expected[5] = {-4, -3, -2, -1, 0};

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(expected[i], actual[i])
            << "Массив ожидаемый и отсортировнный отличаются в элементе с "
               "индексом "
            << i;
    }
}

TEST(BubbleSortTest, ZerosInput) {
    int actual[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    BubbleSort::sort(actual, 10);
    int expected[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(expected[i], actual[i])
            << "Массив ожидаемый и отсортировнный отличаются в элементе с "
               "индексом "
            << i;
    }
}

TEST(BubbleSortTest, SimilarInput) {
    int actual[] = {1, 1, 1};
    BubbleSort::sort(actual, 3);
    int expected[] = {1, 1, 1};

    for (int i = 0; i < 3; i++) {
        ASSERT_EQ(expected[i], actual[i])
            << "Ошибка при сортировке массива одинаковых значений";
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
