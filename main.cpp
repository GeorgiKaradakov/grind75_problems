#include "049-lowest-common-ancestor-of-binary-tree.h"
#include <cstdio>

using namespace std;

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
  print_vec(to_vec(Solution().lowestCommonAncestor(
      from_vec({3, 5, 1, 6, 2, 0, 8, INT_MAX, INT_MAX, 7, 4}), from_vec({5}),
      from_vec({1}))));

  print_vec(to_vec(Solution().lowestCommonAncestor(
      from_vec({3, 5, 1, 6, 2, 0, 8, INT_MAX, INT_MAX, 7, 4}), from_vec({5}),
      from_vec({4}))));
  return 0;
}
