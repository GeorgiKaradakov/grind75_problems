#include "045-search-in-rotated-sorted-array.h"
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
  printf("%d\n", Solution().search({4, 5, 6, 7, 0, 1, 2}, 0));
  printf("%d\n", Solution().search({4, 5, 6, 7, 0, 1, 2}, 3));
  printf("%d\n", Solution().search({1}, 0));
  return 0;
}
