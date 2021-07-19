#ifndef BASIC_ALGOS_ALGOS_LEETCODE_19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H_
#define BASIC_ALGOS_ALGOS_LEETCODE_19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H_

// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

namespace {

// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/
class Solution {
 public:
  int getLength(ListNode *head) {
    int length = 0;
    while (head) {
      ++length;
      head = head->next;
    }
    return length;
  }

  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0, head);
    int length = getLength(head);
    ListNode *cur = dummy;
    for (int i = 1; i < length - n + 1; ++i) {
      cur = cur->next;
    }
    cur->next = cur->next->next;
    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
  }
};

}

#endif //BASIC_ALGOS_ALGOS_LEETCODE_19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H_
