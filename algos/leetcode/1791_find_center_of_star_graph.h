// https://leetcode.com/problems/find-center-of-star-graph/submissions/
#ifndef EVERFLOW_ALGOS_LEETCODE_1791_FIND_CENTER_OF_STAR_GRAPH_H_
#define EVERFLOW_ALGOS_LEETCODE_1791_FIND_CENTER_OF_STAR_GRAPH_H_

class Solution {
 public:
  int findCenter(vector<vector<int>>& edges) {

    if ((edges[0][0] ^ edges[1][0]) == 0 || (edges[0][0] ^ edges[1][1]) == 0 ) {
      return edges[0][0];
    }

    return edges[0][1];
  }
};

#endif //EVERFLOW_ALGOS_LEETCODE_1791_FIND_CENTER_OF_STAR_GRAPH_H_
