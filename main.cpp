#include "week_1/015-climbing-stairs.h"
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
  printf("%d\n", Solution().climbStairs(2));
  printf("%d\n", Solution().climbStairs(3));
  return 0;
}
