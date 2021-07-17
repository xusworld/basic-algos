#ifndef EVERFLOW_ALGOS_LEETCODE_977_H_
#define EVERFLOW_ALGOS_LEETCODE_977_H_

namespace algos {

// Runtime: 20 ms, faster than 97.98% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 25.8 MB, less than 78.43% of C++ online submissions for Squares of a Sorted Array.
class Solution {
 public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n);
    int s = 0, e = n - 1, idx = n - 1;

    while (s <= e) {
      if (abs(nums[s]) < abs(nums[e])) {
        res[idx--] = nums[e] * nums[e];
        e--;
      } else {
        res[idx--] = nums[s] * nums[s];
        s++;
      }
    }

    return res;

  }
};

} // namesapce algos
#endif //EVERFLOW_ALGOS_LEETCODE_977_H_
