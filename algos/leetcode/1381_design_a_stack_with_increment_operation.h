// https://leetcode.com/problems/design-a-stack-with-increment-operation/
#ifndef EVERFLOW_ALGOS_LEETCODE_1381_DESIGN_A_STACK_WITH_INCREMENT_OPERATION_H_
#define EVERFLOW_ALGOS_LEETCODE_1381_DESIGN_A_STACK_WITH_INCREMENT_OPERATION_H_


namespace algos {


class CustomStack {
 public:
  CustomStack(int maxSize) : max_size_(maxSize){}

  void push(int x) {
    if (nums_.size() < max_size_) {
      nums_.push_back(x);
    }
  }

  int pop() {
    if (nums_.size() == 0) {
      return -1;
    }

    int tail = nums_[nums_.size()-1];
    nums_.pop_back();
    return tail;
  }

  void increment(int k, int val) {
    for (int i = 0; i < k && i < nums_.size(); ++i) {
      nums_[i] += val;
    }
  }

 private:
  std::vector<int> nums_;
  int max_size_;
};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_1381_DESIGN_A_STACK_WITH_INCREMENT_OPERATION_H_
