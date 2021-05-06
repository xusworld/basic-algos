#ifndef EVERFLOW_ALGOS_SORT_INSERT_SORT_H_
#define EVERFLOW_ALGOS_SORT_INSERT_SORT_H_

namespace algos {

void InsertionSort(std::vector<int> &inputs) {
  for (int i = 1; i < inputs.size(); ++i) {
    int key = inputs[i];

    // 将 inputs[i] 插入已经排序的 inputs[0 ... i-1] 序列中
    int j = i - 1;
    // 在已经排序的元素序列中从后向前扫描
    while (j >= 0 && inputs[j] > key) {
      // 如果该元素大于新元素，将该元素移动到下一位置
      inputs[j + 1] = inputs[j];
      j--;
    }

    // 插入新元素
    inputs[j + 1] = key;
  }
}

} // namespace algos

#endif //EVERFLOW_ALGOS_SORT_INSERT_SORT_H_
