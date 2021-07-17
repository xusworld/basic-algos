#include "gtest/gtest.h"

#include "algos/sort/counting_sort.h"

TEST(Sort, CountingSort) {
  std::vector<int> inputs = {2, 5, 3, 0, 2, 3, 0, 3};
  auto output = algos::CountingSort(inputs, 5);

  std::vector<int> excepted = {0, 0, 2, 2, 3, 3, 3, 5};
  ASSERT_EQ(excepted, output);
}