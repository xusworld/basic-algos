// https://leetcode-cn.com/problems/intersection-of-three-sorted-arrays/
#ifndef EVERFLOW_ALGOS_LEETCODE_1213_INTERSECTION_OF_THREE_SORTED_ARRAYS_H_
#define EVERFLOW_ALGOS_LEETCODE_1213_INTERSECTION_OF_THREE_SORTED_ARRAYS_H_

namespace algos {

// 原始解法
// 这种直观解法没有利用数组是严格升序排列的
class Solution {
 public:
  vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {

    map<int, int> buckets;
    for (auto val : arr1) {
      buckets[val]++;
    }
    for (auto val : arr2) {
      buckets[val]++;
    }
    for (auto val : arr3) {
      buckets[val]++;
    }

    vector<int> result;
    for (auto val : buckets) {
      if (val.second == 3)
        result.push_back(val.first);
    }
    return result;
  }
};

// 三指针法，不需要额外的空间复杂度
class Solution {
 public:
  vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;

    vector<int> result;
    while (index1 < arr1.size() && index2 < arr2.size() && index3 < arr3.size()) {
      if (arr1[index1] == arr2[index2] && arr2[index2] == arr3[index3]) {
        result.push_back(arr1[index1]);
        index1++;
        index2++;
        index3++;
      } else {
        int max_number = maxOfThree(arr1[index1], arr2[index2], arr3[index3]);
        if (arr1[index1] < max_number)
          index1++;

        if (arr2[index2] < max_number)
          index2++;

        if (arr3[index3] < max_number)
          index3++;
      }
    }

    return result;
  }

  int maxOfThree(int num1, int num2, int num3) {
    return max(num1, max(num2, num3));
  }
};

} // namespace algos


#endif //EVERFLOW_ALGOS_LEETCODE_1213_INTERSECTION_OF_THREE_SORTED_ARRAYS_H_
