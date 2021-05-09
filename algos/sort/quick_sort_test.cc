#include "gtest/gtest.h"

#include "algos/sort/quick_sort.h"

TEST(Sort, QuickSort) {
  std::vector<int> inputs = {2, 8, 7, 1, 3, 6, 5, 4};
  algos::QuickSort(inputs, 0, inputs.size() - 1);

  std::vector<int> excepted = {1, 2, 3, 4, 5, 6, 7, 8};
  ASSERT_EQ(excepted, inputs);
}