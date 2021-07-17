#include "gtest/gtest.h"

#include "algos/search/sequence_search.h"

TEST(Search, SequenceSearch) {
  std::vector<int> inputs = {2, 5, 3, 0, 2, 3, 0, 3};
  int index = algos::SequenceSearch(inputs,  0);

  int excepted = 3;
  ASSERT_EQ(excepted, index);
}