#include "../utils/LinkedList.h"

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *s = head, *f = head->next;

    while (f) {
      s = s->next;
      if (f->next)
        f = f->next->next;
      else
        f = f->next;
    }

    return s;
  }
};
