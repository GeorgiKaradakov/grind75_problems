#include "week_2/030-01-matrix.h"
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
  print_mat(Solution().updateMatrix({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}));
  print_mat(Solution().updateMatrix({{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}));
  return 0;
}
