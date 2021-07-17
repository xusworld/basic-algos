// https://leetcode.com/problems/delete-columns-to-make-sorted/
#ifndef EVERFLOW_ALGOS_LEETCODE_944_DELETE_COLUMNS_TO_MAKE_SORTED_H_
#define EVERFLOW_ALGOS_LEETCODE_944_DELETE_COLUMNS_TO_MAKE_SORTED_H_

namespace algos {

// Runtime: 32 ms, faster than 99.31% of C++ online submissions for Delete Columns to Make Sorted.
// Memory Usage: 12 MB, less than 94.65% of C++ online submissions for Delete Columns to Make Sorted.
class Solution {
 public:
  int minDeletionSize(vector<string> &strs) {
    int col_number = 0;
    for (int col = 0; col < strs[0].size(); ++col) {
      for (int row = 0; row < strs.size() - 1; ++row) {
        if (strs[row][col] > strs[row + 1][col]) {
          col_number++;
          break;
        }
      }
    }
    return col_number;
  }
};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_944_DELETE_COLUMNS_TO_MAKE_SORTED_H_
