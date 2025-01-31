#include "week_1/020-diameter-of-binary-tree.h"
#include <cstdio>

#define print_vec(vec)                                                         \
  for (int n : vec)                                                            \
    printf("%d, ", n);                                                         \
  printf("\n");

#define print_mat(vec)                                                         \
  for (vector<int> v : vec) {                                                  \
    for (int n : v)                                                            \
      printf("%d, ", n);                                                       \
    printf("\n");                                                              \
  }                                                                            \
  printf("\n");

int main(int argc, char *argv[]) {
  printf("%d\n", Solution().diameterOfBinaryTree(from_vec({1, 2, 3, 4, 5})));
  printf("%d\n", Solution().diameterOfBinaryTree(from_vec({1, 2})));
  return 0;
}
