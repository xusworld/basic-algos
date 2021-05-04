#ifndef EVERFLOW_ALGOS_SORT_COUNTING_SORT_H_
#define EVERFLOW_ALGOS_SORT_COUNTING_SORT_H_

#include <vector>

namespace algos {

// 《算法导论》 第8章 线性时间排序
// 计数排序的基本思想是 "对每一个输入元素 x, 确定小于x的元素个数。利用
// 这一信息，可以直接把 x 放到它在输出数组中的位置上了"
std::vector<int> CountingSort(std::vector<int> inputs, int K) {
  std::vector<int> count(K+1, 0);
  // 1. 统计待排序数组中每个元素出现的次数
  for (int i = 0; i < inputs.size(); ++i) {
    count[inputs[i]]++;
  }
  // 2. 计算小于等于元素值i的元素个数
  for (int i = 1; i < count.size(); ++i) {
    count[i] += count[i - 1];
  }

  std::vector<int> sorted(inputs.size(), 0);

  // 3. 输出结果
  for (int i = inputs.size() - 1; i >= 0; --i) {
    sorted[count[inputs[i]]-1] = inputs[i];
    count[inputs[i]]--;
  }

  return sorted;
}

} // namespace algos

#endif //EVERFLOW_ALGOS_SORT_COUNTING_SORT_H_
