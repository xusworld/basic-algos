// https://leetcode-cn.com/problems/sum-of-square-numbers/
#ifndef EVERFLOW_ALGOS_LEETCODE_633_SUM_OF_SQUARE_NUMBERS_H_
#define EVERFLOW_ALGOS_LEETCODE_633_SUM_OF_SQUARE_NUMBERS_H_

namespace algos {

class Solution {
 public:
  bool judgeSquareSum(int c) {
    long left = 0;
    long right = (int) sqrt(c);
    while (left <= right) {
      long sum = left * left + right * right;
      if (sum == c) {
        return true;
      } else if (sum > c) {
        right--;
      } else {
        left++;
      }
    }
    return false;
  }
};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_633_SUM_OF_SQUARE_NUMBERS_H_
