// Leetcode 题目地址 https://leetcode.com/problems/min-stack/
#ifndef EVERFLOW_ALGOS_LEETCODE_MIN_STACK_H_
#define EVERFLOW_ALGOS_LEETCODE_MIN_STACK_H_

namespace algos {

class MinStack {
 public:
  MinStack() {}

  void push(int val) {
    stack_.push(val);

    if (min_stack_.empty()) {
      min_stack_.push(val);
    } else {
      min_stack_.push(min(val, min_stack_.top()));
    }
  }

  void pop() {
    stack_.pop();
    min_stack_.pop();
  }

  int top() {
    return nums_.top();
  }

  int getMin() {
    return min_stack_.top();
  }
 private:
  std::stack<int> min_stack_;
  std::stack<int> stack_;
};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_MIN_STACK_H_
