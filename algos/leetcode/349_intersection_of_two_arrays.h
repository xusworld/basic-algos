// https://leetcode-cn.com/problems/intersection-of-two-arrays/
#ifndef EVERFLOW_ALGOS_LEETCODE_349_INTERSECTION_OF_TWO_ARRAYS_H_
#define EVERFLOW_ALGOS_LEETCODE_349_INTERSECTION_OF_TWO_ARRAYS_H_

namespace algos {

// 原始思路解法
class Solution {
 public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> buckets1;
    for (auto val : nums1) {
      buckets1[val]++;
    }

    unordered_map<int, int> buckets2;
    for (auto val : nums2) {
      buckets2[val]++;
    }

    vector<int> result;
    for (auto val : buckets1) {
      if (buckets2.find(val.first) != buckets2.end())
        result.push_back(val.first);
    }
    return result;
  }
};

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  int length1 = nums1.size(), length2 = nums2.size();
  int index1 = 0, index2 = 0;
  vector<int> intersection;
  while (index1 < length1 && index2 < length2) {
    int num1 = nums1[index1], num2 = nums2[index2];
    if (num1 == num2) {
      // 保证加入元素的唯一性
      if (!intersection.size() || num1 != intersection.back()) {
        intersection.push_back(num1);
      }
      index1++;
      index2++;
    } else if (num1 < num2) {
      index1++;
    } else {
      index2++;
    }
  }
  return intersection;
}

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_349_INTERSECTION_OF_TWO_ARRAYS_H_
