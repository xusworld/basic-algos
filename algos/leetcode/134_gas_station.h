// https://leetcode.com/problems/gas-station/
#ifndef EVERFLOW_ALGOS_LEETCODE_134_GAS_STATION_H_
#define EVERFLOW_ALGOS_LEETCODE_134_GAS_STATION_H_

// 自己实现的垃圾解法
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    int start_pos = -1;
    for (int i = 0; i < gas.size(); ++i) {

      int sum = 0;

      for(int j = i ; j < i + gas.size();  ++j) {
        int idx = j % gas.size();
        sum += gas[idx] - cost[idx];

        if (sum < 0) {
          break;
        }

      }

      if (sum >= 0) {
        return i;
      }

    }

    return -1;
  }
};

#endif //EVERFLOW_ALGOS_LEETCODE_134_GAS_STATION_H_
