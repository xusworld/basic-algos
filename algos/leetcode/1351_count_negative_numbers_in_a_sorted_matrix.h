// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
#ifndef EVERFLOW_ALGOS_LEETCODE_1351_COUNT_NEGATIVE_NUMBERS_IN_A_SORTED_MATRIX_H_
#define EVERFLOW_ALGOS_LEETCODE_1351_COUNT_NEGATIVE_NUMBERS_IN_A_SORTED_MATRIX_H_

namespace algos {

// Runtime: 16 ms, faster than 58.17% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
// Memory Usage: 10.4 MB, less than 74.79% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
class Solution {
 public:
  int countNegatives(vector<vector<int>> &grid) {
    // 从矩阵的右下角开始查找
    int m = grid.size();
    int n = grid[0].size();
    int negative_num_count = 0;
    for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; i--, j--) {

      if (grid[i][j] < 0) {
        ++negative_num_count;
      }

      // TODO 下面两个查找可以使用二分法
      for (int k = j - 1; k >= 0 && grid[i][k] < 0; k--) {
        ++negative_num_count;
      }

      for (int k = i - 1; k >= 0 && grid[k][j] < 0; k--) {
        ++negative_num_count;
      }

    }

    return negative_num_count;
  }

  // 时间复杂度更好的方法
  // Runtime: 12 ms, faster than 92.70% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
  // Memory Usage: 10.5 MB, less than 33.44% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.

  class Solution2 {
   public:
    int countNegatives(vector<vector<int>> &grid) {
      int m = grid.size();
      int n = grid[0].size();
      int i = 0;
      int j = n - 1;
      int ans = 0;
      while (i < m and j >= 0) {
        while (j >= 0 and grid[i][j] < 0) {
          ans += (m - i);
          j--;
        }
        i++;
      }
      return ans;
    }
  };

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_1351_COUNT_NEGATIVE_NUMBERS_IN_A_SORTED_MATRIX_H_
