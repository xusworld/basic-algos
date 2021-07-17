// https://leetcode.com/problems/implement-stack-using-queues/
#ifndef EVERFLOW_ALGOS_LEETCODE_232_IMPLEMENT_QUEUE_USING_STACKS_H_
#define EVERFLOW_ALGOS_LEETCODE_232_IMPLEMENT_QUEUE_USING_STACKS_H_

namespace algos {

class MyStack {
 public:
  MyStack() {}

  // Push element x onto stack.
  void push(int x) {
    queue_.push(x);

    for (int i = 0; i < queue_.size() - 1; ++i) {
      queue_.push(queue_.front());
      queue_.pop();
    }
  }

  // Removes the element on top of the stack and returns that element
  int pop() {
    int top = queue_.front();
    queue_.pop();
    return top;
  }

  // Get the top element.
  int top() {
    return queue_.front();
  }

  // Returns whether the stack is empty.
  bool empty() {
    return queue_.empty();
  }

 private:
  queue<int> queue_;
};


} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_232_IMPLEMENT_QUEUE_USING_STACKS_H_
