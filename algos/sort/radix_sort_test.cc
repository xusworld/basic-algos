#include "gtest/gtest.h"

#include "algos/sort/radix_sort.h"

TEST(Sort, RadixSort) {
  std::vector<int> inputs = {329, 457, 657, 839, 436, 720, 355};
  algos::RadixSort(inputs);

  std::vector<int> excepted = {329, 355, 436, 457, 657, 720, 839};
  ASSERT_EQ(excepted, inputs);
}