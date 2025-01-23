#include "../utils/LinkedList.h"
#include <cstdio>
#include <stdatomic.h>

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *node = new ListNode();
    ListNode *b = node;

    while (list1 || list2) {
      if (list1 && list2) {
        if (list1->val > list2->val) {
          b->next = new ListNode(list2->val);
          list2 = list2->next;
        } else {
          b->next = new ListNode(list1->val);
          list1 = list1->next;
        }
      } else if (list1) {
        b->next = new ListNode(list1->val);
        list1 = list1->next;
      } else if (list2) {
        b->next = new ListNode(list2->val);
        list2 = list2->next;
      }

      b = b->next;
    }

    return node->next;
  }
};
