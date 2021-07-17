// https://leetcode.com/problems/sort-colors/
#ifndef EVERFLOW_ALGOS_LEETCODE_75_SORT_COLORS_H_
#define EVERFLOW_ALGOS_LEETCODE_75_SORT_COLORS_H_


namespace algos {


// 直观思路，性能极差
// Runtime: 4 ms, faster than 44.75% of C++ online submissions for Sort Colors.
// Memory Usage: 8.2 MB, less than 63.25% of C++ online submissions for Sort Colors.
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int red_count = 0;
    int white_count = 0;
    int blue_count = 0;

    for(int i = 0; i < nums.size(); ++i) {
      switch(nums[i]) {
        case 0:
          red_count++;
          break;
        case 1:
          white_count++;
          break;
        case 2:
          blue_count++;
          break;
      }
    }

    for(int i = 0; i < nums.size(); i++) {
      if(i < red_count) {
        nums[i] = 0;
      } else if(i >= red_count && i < (red_count + white_count)) {
        nums[i] = 1;
      } else {
        nums[i] = 2;
      }
    }
  }
};


}


#endif //EVERFLOW_ALGOS_LEETCODE_75_SORT_COLORS_H_
