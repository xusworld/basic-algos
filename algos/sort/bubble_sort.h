#ifndef EVERFLOW_ALGOS_SORT_BUBBLE_SORT_H_
#define EVERFLOW_ALGOS_SORT_BUBBLE_SORT_H_

namespace algos {

void BubbleSort(std::vector<int>& inputs) {
  int N = inputs.size();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N - 1 - i; ++j) {
      if (inputs[j] > inputs[j + 1]) {
        std::swap(inputs[j], inputs[j + 1]);
      }
    }
  }
}

} // namespace algos

#endif //EVERFLOW_ALGOS_SORT_BUBBLE_SORT_H_
