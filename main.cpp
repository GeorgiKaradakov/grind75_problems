#include "052-sort-colors.h"
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
  vector<int> a = {2, 0, 2, 1, 1, 0};
  Solution().sortColors(a);
  print_vec(a);

  a = {2, 0, 1};
  Solution().sortColors(a);
  print_vec(a);
  return 0;
}
