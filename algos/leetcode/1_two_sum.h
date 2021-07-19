#ifndef BASIC_ALGOS_ALGOS_LEETCODE_1_TWO_SUM_H_
#define BASIC_ALGOS_ALGOS_LEETCODE_1_TWO_SUM_H_

// https://leetcode-cn.com/problems/two-sum/

namespace {

/*
 *  使用哈希表，可以将寻找 target - x 的时间复杂度降低到从 O(N) 降低到 O(1)。
 *  这样我们创建一个哈希表，对于每一个 x，我们首先查询哈希表中是否存在 target - x，
 *  然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配。
 */

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = hashtable.find(target - nums[i]);
      if (it != hashtable.end()) {
        return {it->second, i};
      }
      hashtable[nums[i]] = i;
    }
    return {};
  }
};

} // namespace

#endif //BASIC_ALGOS_ALGOS_LEETCODE_1_TWO_SUM_H_
