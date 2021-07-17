// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
#ifndef EVERFLOW_ALGOS_LEETCODE_1356_SORT_INTEGERS_BY_THE_NUMBER_OF_1_BITS_H_
#define EVERFLOW_ALGOS_LEETCODE_1356_SORT_INTEGERS_BY_THE_NUMBER_OF_1_BITS_H_

namespace algos {

// Runtime: 12 ms, faster than 42.03% of C++ online submissions for Sort Integers by The Number of 1 Bits.
// Memory Usage: 10.7 MB, less than 25.19% of C++ online submissions for Sort Integers by The Number of 1 Bits.
int BitCount(int n) {
  int c = 0;
  while (n > 0) {
    if ((n & 1) == 1)
      ++c;

    n >>= 1;
  }
  return c;
}

// 原始思路，无论是时间复杂度还是空间复杂度都极差
class Solution {
 public:
  vector<int> sortByBits(vector<int> &arr) {
    vector<vector<int>> buckets(15, vector<int>(0, 0));
    for (int i = 0; i < arr.size(); ++i) {
      buckets[BitCount(arr[i])].push_back(arr[i]);
    }

    vector<int> result;
    for (int i = 0; i < buckets.size(); ++i) {
      sort(buckets[i].begin(), buckets[i].end());
      result.insert(result.end(), buckets[i].begin(), buckets[i].end());
    }
    return result;
  }
};

// Runtime: 8 ms, faster than 82.18% of C++ online submissions for Sort Integers by The Number of 1 Bits.
// Memory Usage: 10.8 MB, less than 18.50% of C++ online submissions for Sort Integers by The Number of 1 Bits.
class Solution {
 public:
  vector<int> sortByBits(vector<int> &arr) {
    // 调整排序位置
    sort(arr.begin(), arr.end());

    vector<vector<int>> buckets(15, vector<int>(0, 0));
    for (int i = 0; i < arr.size(); ++i) {
      buckets[BitCount(arr[i])].push_back(arr[i]);
    }

    vector<int> result;
    for (int i = 0; i < buckets.size(); ++i) {

      result.insert(result.end(), buckets[i].begin(), buckets[i].end());
    }
    return result;
  }
};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_1356_SORT_INTEGERS_BY_THE_NUMBER_OF_1_BITS_H_
