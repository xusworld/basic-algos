// https://leetcode.com/problems/custom-sort-string/
#ifndef EVERFLOW_ALGOS_LEETCODE_791_CUSTOM_SORT_STRING_H_
#define EVERFLOW_ALGOS_LEETCODE_791_CUSTOM_SORT_STRING_H_

namespace algos {

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Custom Sort String.
// Memory Usage: 6.2 MB, less than 69.99% of C++ online submissions for Custom Sort String.
class Solution {
 public:
  string customSortString(string S, string T) {
    vector<int> bucket(26, 0);

    for (int i = 0; i < T.length(); ++i) {
      bucket[T[i] - 97]++;
    }

    string result("");
    for (int i = 0; i < S.length(); ++i) {
      result += string(bucket[S[i] - 97], S[i]);
      bucket[S[i] - 97] = 0;
    }

    for (int i = 0; i < bucket.size(); ++i) {
      if (bucket[i] > 0) {
        result += string(bucket[i], char(i + 97));
      }
    }
    return result;

  }
};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_791_CUSTOM_SORT_STRING_H_
