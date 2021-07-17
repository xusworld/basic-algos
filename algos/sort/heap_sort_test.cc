#include "gtest/gtest.h"

#include "algos/sort/heap_sort.h"

TEST(Sort, HeapSort) {
  std::vector<int> inputs = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
  algos::MaxHeapify(inputs, 1, inputs.size() - 1);
  std::vector<int> excepted = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  ASSERT_EQ(excepted, inputs);

  std::vector<int> inputs1 = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  algos::BuildMaxHeap(inputs1);
  std::vector<int> excepted1 = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  ASSERT_EQ(excepted1, inputs1);

  std::vector<int> inputs2 = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  algos::HeapSort(inputs2);
  std::vector<int> excepted2 = {1, 2, 3, 4, 7, 8, 9, 10, 14, 16};
  ASSERT_EQ(excepted2, inputs2);
}