// https://leetcode.com/problems/merge-sorted-array/
#ifndef EVERFLOW_ALGOS_LEETCODE_88_MERGE_SORTED_ARRAY_H_
#define EVERFLOW_ALGOS_LEETCODE_88_MERGE_SORTED_ARRAY_H_

namespace algos {

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 9.1 MB, less than 16.17% of C++ online submissions for Merge Sorted Array.
class Solution {
 public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
      if (nums1[i] >= nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }

    while (i >= 0) {
      nums1[k--] = nums1[i--];
    }

    while (j >= 0) {
      nums1[k--] = nums2[j--];
    }
  }
};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_88_MERGE_SORTED_ARRAY_H_
