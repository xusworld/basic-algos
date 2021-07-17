// https://leetcode.com/problems/build-an-array-with-stack-operations/
#ifndef EVERFLOW_ALGOS_LEETCODE_1441_BUILD_AN_ARRAY_WITH_STACK_OPERATIONS_H_
#define EVERFLOW_ALGOS_LEETCODE_1441_BUILD_AN_ARRAY_WITH_STACK_OPERATIONS_H_

namespace algos {

class Solution {
 public:
  vector<string> buildArray(vector<int> &target, int n) {
    vector<string> output;

    for (int i = 1, j = 0; i <= n && j < target.size(); ++i) {
      if (target[j] == i) {
        output.push_back("Push");
        j++;
      } else {
        output.push_back("Push");
        output.push_back("Pop");
      }
    }

    return output;
  }
};

} // namespace algos


#endif //EVERFLOW_ALGOS_LEETCODE_1441_BUILD_AN_ARRAY_WITH_STACK_OPERATIONS_H_
