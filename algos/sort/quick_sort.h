#ifndef EVERFLOW_ALGOS_SORT_QUICK_SORT_H_
#define EVERFLOW_ALGOS_SORT_QUICK_SORT_H_

namespace algos {

int Partition(std::vector<int> &inputs, int first, int last) {
  // 使用第一个元素作为 主元 (pivot element)
  int key = inputs[first];

  int begin = first;
  int end = last;
  while (begin < end) {
    while (begin < end && inputs[end] > key) {
      end--;
    }

    while (begin < end && inputs[begin] < key) {
      begin++;
    }

    if (begin < end)
      std::swap(inputs[begin], inputs[end]);

  }

  inputs[first] = inputs[begin];
  inputs[begin] = key;
  return begin;
}

void QuickSort(std::vector<int> inputs, int first, int last) {
  if (first < last) {
    int pivot = Partition(inputs, first, last);
    QuickSort(inputs, first, pivot);
    QuickSort(inputs, pivot + 1, last);
  }
}

} // namespace algos


#endif //EVERFLOW_ALGOS_SORT_QUICK_SORT_H_
