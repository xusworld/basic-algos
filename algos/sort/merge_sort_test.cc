#include "gtest/gtest.h"

#include "algos/sort/merge_sort.h"

TEST(Sort, MergeSort) {
  std::vector<int> inputs = {2, 5, 3, 0, 2, 3, 0, 3};
  algos::MergeSort(inputs, 0, inputs.size() - 1);

  std::vector<int> excepted = {0, 0, 2, 2, 3, 3, 3, 5};
  ASSERT_EQ(excepted, inputs);
}