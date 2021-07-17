#include "gtest/gtest.h"

#include "algos/sort/insert_sort.h"

TEST(Sort, InsertSort) {
  std::vector<int> inputs = {2, 5, 3, 0, 2, 3, 0, 3};
  algos::InsertionSort(inputs);

  std::vector<int> excepted = {0, 0, 2, 2, 3, 3, 3, 5};
  ASSERT_EQ(excepted, inputs);
}