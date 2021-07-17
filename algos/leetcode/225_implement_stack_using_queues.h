// https://leetcode.com/problems/implement-queue-using-stacks/
#ifndef EVERFLOW_ALGOS_LEETCODE_225_IMPLEMENT_STACK_USING_QUEUES_H_
#define EVERFLOW_ALGOS_LEETCODE_225_IMPLEMENT_STACK_USING_QUEUES_H_

namespace algos {

class MyQueue {
 public:
  // Initialize your data structure here.
  MyQueue() {}

  // Push element x to the back of queue.
  void push(int x) {
    stack1_.push(x);
  }

  // Removes the element from in front of queue and returns that element.
  int pop() {
    // 判断 stack2 是否为空
    if (!stack2_.empty()) {
      int val = stack2_.top();
      stack2_.pop();
      return val;
    }

    // 如果 stack2 为空，将 stack1 中的元素全部转移到 stack2 中
    while (!stack1_.empty()) {
      auto val = stack1_.top();
      stack1_.pop();
      stack2_.push(val);
    }

    // 此时 stack2 栈顶元素为 队列第一个元素
    auto val = stack2_.top();
    stack2_.pop();
    return val;
  }

  /** Get the front element. */
  int peek() {
    // 判断 stack2 是否为空
    if (!stack2_.empty()) {
      int val = stack2_.top();
      return val;
    }

    while (!stack1_.empty()) {
      auto val = stack1_.top();
      stack1_.pop();
      stack2_.push(val);
    }
    // 此时 stack2 栈顶元素为 队列第一个元素
    auto val = stack2_.top();
    return val;
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    if (stack1_.empty() && stack2_.empty()) {
      return true;
    }
    return false;
  }
 private:
  std::stack<int> stack1_;
  std::stack<int> stack2_;

};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_225_IMPLEMENT_STACK_USING_QUEUES_H_
