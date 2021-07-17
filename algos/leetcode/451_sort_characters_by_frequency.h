
#ifndef EVERFLOW_ALGOS_LEETCODE_451_SORT_CHARACTERS_BY_FREQUENCY_H_
#define EVERFLOW_ALGOS_LEETCODE_451_SORT_CHARACTERS_BY_FREQUENCY_H_

namespace algos {


// Runtime: 4 ms, faster than 99.80% of C++ online submissions for Sort Characters By Frequency.
// Memory Usage: 8.9 MB, less than 21.52% of C++ online submissions for Sort Characters By Frequency.
inline int charToIndex(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }

  if (c >= 'A' && c <= 'Z') {
    return c - 'A' + 10;
  }

  if (c >= 'a' && c <= 'z') {
    return c - 'a' + 36;
  }
  return 0;
}

inline char intToChar(int n) {
  if (n >= 0 && n <= 9) {
    return char(n + 48);
  }

  if (n >= 10 && n < 36) {
    return char(n - 10 + 65);
  }

  if (n >= 36 && n < 63) {
    return char(n - 36 + 97);
  }
  return '0';
}

class Solution {
 public:
  string frequencySort(string s) {
    vector<int> count_bucket(62, 0);

    for (int i = 0; i < s.length(); ++i) {
      count_bucket[charToIndex(s[i])]++;
    }

    map<int, vector<char>> sorted_bucket;
    for (int i = 0; i < count_bucket.size(); ++i) {
      sorted_bucket[count_bucket[i]].push_back(intToChar(i));
    }
    string result;
    for (auto iter = sorted_bucket.rbegin(); iter != sorted_bucket.rend(); ++iter) {
      for (int i = 0; i < iter->second.size(); ++i) {
        result += string(iter->first, iter->second[i]);
      }
    }
    return result;
  }

};

} // namespace aglos

#endif //EVERFLOW_ALGOS_LEETCODE_451_SORT_CHARACTERS_BY_FREQUENCY_H_
