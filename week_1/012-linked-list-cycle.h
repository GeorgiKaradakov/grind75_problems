#pragma once

#include "../utils/LinkedList.h"

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head)
      return 0;

    ListNode *curr = head, *fast = head->next;

    while (curr && fast) {
      if (curr == fast) {
        return 1;
      }

      curr = curr->next;
      if (fast->next)
        fast = fast->next->next;
      else
        fast = fast->next;
    }

    return 0;
  }
};
