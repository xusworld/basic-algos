// https://leetcode.com/problems/sort-array-by-increasing-frequency/
#ifndef EVERFLOW_ALGOS_LEETCODE_1636_SORT_ARRAY_BY_INCREASING_FREQUENCY_H_
#define EVERFLOW_ALGOS_LEETCODE_1636_SORT_ARRAY_BY_INCREASING_FREQUENCY_H_

namespace algos {

// Runtime: 4 ms, faster than 94.74% of C++ online submissions for Sort Array by Increasing Frequency.
//Memory Usage: 11.7 MB, less than 13.81% of C++ online submissions for Sort Array by Increasing Frequency.
class Solution {
 public:
  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> frequency_bucket;

    for (int i = 0; i < nums.size(); ++i) {
      frequency_bucket[nums[i]]++;
    }

    map<int, vector<int>> bucket;
    for (auto val: frequency_bucket) {
      bucket[val.second].push_back(val.first);
    }

    vector<int> result;
    int i = 0;
    for (auto val : bucket) {
      if (val.second.size() > 1) {
        sort(val.second.begin(), val.second.end(), greater<int>());
      }
      for (int j = 0; j < val.second.size(); ++j) {
        for (int k = 0; k < val.first; ++k) {
          result.push_back(val.second[j]);
        }
      }
    }
    return result;
  }
};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_1636_SORT_ARRAY_BY_INCREASING_FREQUENCY_H_
