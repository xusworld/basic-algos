// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
#ifndef EVERFLOW_ALGOS_LEETCODE_1450_NUMBER_OF_STUDENTS_DOING_HOMEWORK_AT_A_GIVEN_TIME_H_
#define EVERFLOW_ALGOS_LEETCODE_1450_NUMBER_OF_STUDENTS_DOING_HOMEWORK_AT_A_GIVEN_TIME_H_

namespace algos {

class Solution {
 public:
  int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
    int result = 0;

    for (int i = 0; i < startTime.size(); ++i) {
      if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
        result++;
      }
    }

    return result;
  }
};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_1450_NUMBER_OF_STUDENTS_DOING_HOMEWORK_AT_A_GIVEN_TIME_H_
