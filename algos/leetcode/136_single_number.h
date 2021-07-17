// https://leetcode-cn.com/problems/single-number/
#ifndef EVERFLOW_ALGOS_LEETCODE_139_SINGLE_NUMBER_H_
#define EVERFLOW_ALGOS_LEETCODE_139_SINGLE_NUMBER_H_

namespace algos {

// Runtime: 16 ms, faster than 83.31% of C++ online submissions for Single Number.
// Memory Usage: 16.9 MB, less than 78.63% of C++ online submissions for Single Number.
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
      nums[0] ^= nums[i];
    }
    return nums[0];
  }
};

} // namesapce algos

#endif //EVERFLOW_ALGOS_LEETCODE_139_SINGLE_NUMBER_H_
