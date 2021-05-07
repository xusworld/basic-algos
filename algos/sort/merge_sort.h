#ifndef EVERFLOW_ALGOS_SORT_MERGE_SORT_H_
#define EVERFLOW_ALGOS_SORT_MERGE_SORT_H_

namespace algos {

void Merge(std::vector<int> &inputs, int front, int mid, int end) {
  // 切分左右子数组
  std::vector<int> left(inputs.begin() + front, inputs.begin() + mid + 1);
  std::vector<int> right(inputs.begin() + mid + 1, inputs.begin() + end + 1);
  // 合并两个有序数组
  int lidx = 0;
  int ridx = 0;
  // 插入"哨兵"
  left.insert(left.end(), 2147483647);
  right.insert(right.end(), 2147483647);
  for (int i = front; i <= end; ++i) {
    if (left[lidx] < right[ridx]) {
      inputs[i] = left[lidx++];
    } else {
      inputs[i] = right[ridx++];
    }
  }
}

void MergeSort(std::vector<int> &inputs, int front, int end) {
  if (front >= end)
    return;

  int mid = front + (end - front) / 2;
  MergeSort(inputs, front, mid);
  MergeSort(inputs, mid + 1, end);
  Merge(inputs, front, mid, end);
}

} // namespace algos

#endif //EVERFLOW_ALGOS_SORT_MERGE_SORT_H_
