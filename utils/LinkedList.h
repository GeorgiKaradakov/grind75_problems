#pragma once
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode *from_vec(std::vector<int> vec) {
  ListNode *node;

  if (vec.empty())
    return nullptr;

  node = new ListNode(vec[0]);

  ListNode *runner = node;
  for (int i = 1; i < vec.size(); i++) {
    runner->next = new ListNode(vec[i]);
    runner = runner->next;
  }

  return node;
}

inline std::vector<int> to_vec(ListNode *node) {
  if (!node)
    return {};

  std::vector<int> res;
  ListNode *runner = node;

  while (runner) {
    res.push_back(runner->val);
    runner = runner->next;
  }

  return res;
}
