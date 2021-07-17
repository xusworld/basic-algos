#ifndef EVERFLOW_ALGOS_SEARCH_JUMP_SEARCH_H_
#define EVERFLOW_ALGOS_SEARCH_JUMP_SEARCH_H_

namespace algos {

int JumpSearch(std::vector<int> &inputs, int target) {
  int n = inputs.size();
  // Finding block size to be jumped
  int step = sqrt(n);

  // Finding the block where element is
  // present (if it is present)
  int prev = 0;
  while (arr[min(step, n) - 1] < x) {
    prev = step;
    step += sqrt(n);
    if (prev >= n)
      return -1;
  }

  // Doing a linear search for x in block
  // beginning with prev.
  while (arr[prev] < x) {
    prev++;

    // If we reached next block or end of
    // array, element is not present.
    if (prev == min(step, n))
      return -1;
  }
  // If element is found
  if (arr[prev] == x)
    return prev;

  return -1;
}

} // namespace algos

#endif //EVERFLOW_ALGOS_SEARCH_JUMP_SEARCH_H_
