// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#ifndef EVERFLOW_ALGOS_LEETCODE_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_
#define EVERFLOW_ALGOS_LEETCODE_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_

namespace algos {

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *cur = head;

    while (cur->next != nullptr) {

      if (cur->val == cur->next->val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }

    return head;

  }
};

} // namespace algos

#endif //EVERFLOW_ALGOS_LEETCODE_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_
