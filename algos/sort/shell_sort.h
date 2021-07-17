#ifndef EVERFLOW_ALGOS_SORT_SHELL_SORT_H_
#define EVERFLOW_ALGOS_SORT_SHELL_SORT_H_

namespace algos {

// 实现来自维基百科
template<typename T>
void shell_sort(T arr[], int len) {
  int gap, i, j;
  T temp;
  for (gap = len >> 1; gap > 0; gap >>= 1)
    for (i = gap; i < len; i++) {
      temp = arr[i];
      for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
        arr[j + gap] = arr[j];
      arr[j + gap] = temp;
    }
}

} // namespace algos

#endif //EVERFLOW_ALGOS_SORT_SHELL_SORT_H_
