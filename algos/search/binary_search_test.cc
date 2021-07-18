#include "gtest/gtest.h"

#include "algos/search/binary_search.h"

TEST(Search, BinarySearch) {
  std::vector<int> inputs = {1, 2, 3, 5, 8, 9, 11, 14};
  int index = algos::BinarySearch(inputs,  9);

  int excepted = 5;
  ASSERT_EQ(excepted, index);
}