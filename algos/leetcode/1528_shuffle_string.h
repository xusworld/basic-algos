// https://leetcode.com/problems/shuffle-string/
#ifndef EVERFLOW_ALGOS_LEETCODE_1528_SHUFFLE_STRING_H_
#define EVERFLOW_ALGOS_LEETCODE_1528_SHUFFLE_STRING_H_

namespace algos {

class Solution {
 public:
  string restoreString(string s, vector<int>& indices) {
    string result(s);
    for (int i = 0; i < indices.size(); ++i) {
      result[indices[i]] = s[i];
    }
    return result;
  }
};


} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_1528_SHUFFLE_STRING_H_
