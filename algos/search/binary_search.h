#ifndef EVERFLOW_ALGOS_SEARCH_BINARY_SEARCH_H_
#define EVERFLOW_ALGOS_SEARCH_BINARY_SEARCH_H_

namespace algos {

int BinarySearch(std::vector<int> &inputs, int target) {
  int left = 0;
  int right = inputs.size() - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (inputs[mid] == target) {
      return mid;
    } else if (inputs[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

} // namespace algos


#endif //EVERFLOW_ALGOS_SEARCH_BINARY_SEARCH_H_
