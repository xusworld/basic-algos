#ifndef BASIC_ALGOS_ALGOS_LEETCODE_11_CONTAINER_WITH_MOST_WATER_H_
#define BASIC_ALGOS_ALGOS_LEETCODE_11_CONTAINER_WITH_MOST_WATER_H_

// https://leetcode-cn.com/problems/container-with-most-water/

namespace {
// https://leetcode-cn.com/problems/container-with-most-water/solution/yuan-lai-hui-luo-ji-qing-xi-jian-dan-yi-hbxc2/
// 时间复杂度： O(n)
// 空间复杂度： O(1)
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int maxarea = 0;

    while (i < j)
    {
      // 循环遍历, 求面积注意：h是高， h应该是 height[i] height[j]中的”矮“的   ~不然水就漏了~
      // 谁比较“矮”谁优先
      int h = min(height[i], height[j]);
      maxarea = max(maxarea, (j - i) * h);

      // 以下while内做了优化， 左右指针向中间靠拢的时候，如果 h变小，则不需要计算面积了
      while (height[i] <= h && i < j)
        i++;
      while (height[j] <= h && i < j)
        j--;
    }
    return maxarea;
  }
};


} // namespace

#endif //BASIC_ALGOS_ALGOS_LEETCODE_11_CONTAINER_WITH_MOST_WATER_H_
