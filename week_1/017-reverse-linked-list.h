#include "../utils/LinkedList.h"
#include <cstdio>

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *holder = head, *runner = head->next;

    holder->next = nullptr;
    while (runner) {
      ListNode *tmp = runner->next;
      runner->next = holder;
      holder = runner;
      runner = tmp;
    }

    return holder;
  }
};
