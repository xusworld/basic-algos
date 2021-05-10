#ifndef EVERFLOW_ALGOS_SORT_RADIX_SORT_H_
#define EVERFLOW_ALGOS_SORT_RADIX_SORT_H_

namespace algos {

void countSort(std::vector<int> &inputs, int exp) {
  std::vector<int> count(10, 0);

  // 统计输入中每个 (exp)th 位置的数字出现的次数
  for (auto input : inputs) {
    count[(input / exp) % 10]++;
  }

  // 计算小于等于元素值i的元素个数
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  std::vector<int> sorted(inputs.size(), 0);
  // 输出结果
  for (int i = inputs.size() - 1; i >= 0; --i) {
    sorted[count[(inputs[i] / exp) % 10] - 1] = inputs[i];
    count[(inputs[i] / exp) % 10]--;
  }

  inputs.assign(sorted.begin(), sorted.end());
}

void RadixSort(std::vector<int> &inputs) {
  auto iter = std::max_element(inputs.begin(), inputs.end());

  for (int exp = 1; *iter / exp > 0; exp *= 10)
    countSort(inputs, exp);
}

} // namespace algos

#endif //EVERFLOW_ALGOS_SORT_RADIX_SORT_H_
