#ifndef EVERFLOW_ALGOS_SORT_HEAP_SORT_H_
#define EVERFLOW_ALGOS_SORT_HEAP_SORT_H_

namespace algos {

// 返回节点i的父节点
int parent(int i) {
  return (i - 1) / 2;
}

// 返回节点i的左孩子节点
int left(int i) {
  return i * 2 + 1;
}

// 返回节点i的右孩子节点
int right(int i) {
  return 2 * i + 2;
}

// 维护最大堆的性质
void MaxHeapify(std::vector<int> &inputs, int i, int heap_size) {
  int lchild = left(i);
  int rchild = right(i);
  int largest;
  // 从 inputs[i]、inputs[lchild]和inputs[rchild]三者中选择最大的，并将下标存储在largest中
  if (lchild < heap_size && inputs[lchild] > inputs[i])
    largest = lchild;
  else
    largest = i;

  if (rchild < heap_size && inputs[rchild] > inputs[largest])
    largest = rchild;

  // 如果inputs[i]并不是三者中最大的，需要交换inputs[i]和inputs[largest]的值以满足最大堆的性质
  // 交换后，仍需要逐级下降使得子树仍然遵循最大堆的性质
  if (largest != i) {
    std::swap(inputs[i], inputs[largest]);
    MaxHeapify(inputs, largest, heap_size);
  }
}

void BuildMaxHeap(std::vector<int> &inputs) {
  int heap_size = inputs.size();
  for (int i = (heap_size - 1) / 2; i >= 0; --i) {
    MaxHeapify(inputs, i, heap_size);
  }
}

void HeapSort(std::vector<int> &inputs) {
  // 构造最大堆
  BuildMaxHeap(inputs);
  for (int i = inputs.size() - 1; i >= 1; --i) {
    // 最大堆中根节点inputs[0]中保存最大元素，与最后一个元素交换
    std::swap(inputs[0], inputs[i]);
    // 维护最大堆性质
    MaxHeapify(inputs, 0, i);
  }
}

} // namespace algos

#endif //EVERFLOW_ALGOS_SORT_HEAP_SORT_H_
