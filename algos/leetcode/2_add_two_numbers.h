#ifndef BASIC_ALGOS_ALGOS_LEETCODE_2_ADD_TWO_NUMBERS_H_
#define BASIC_ALGOS_ALGOS_LEETCODE_2_ADD_TWO_NUMBERS_H_

// https://leetcode-cn.com/problems/add-two-numbers

namespace {

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr, *tail = nullptr;
    int carry = 0;
    while (l1 || l2) {
      int n1 = l1 ? l1->val : 0;
      int n2 = l2 ? l2->val : 0;
      int sum = n1 + n2 + carry;
      if (!head) {
        head = tail = new ListNode(sum % 10);
      } else {
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
      }
      carry = sum / 10;
      if (l1) {
        l1 = l1->next;
      }
      if (l2) {
        l2 = l2->next;
      }
    }
    if (carry > 0) {
      tail->next = new ListNode(carry);
    }
    return head;
  }
};

} // namespace

#endif //BASIC_ALGOS_ALGOS_LEETCODE_2_ADD_TWO_NUMBERS_H_
