#include "053-word-break.h"
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
  printf("%d\n", Solution().wordBreak("leetcode", {"leet", "code"}));
  printf("%d\n", Solution().wordBreak("applepenapple", {"apple", "pen"}));
  printf("%d\n", Solution().wordBreak("catsandog",
                                      {"cats", "dog", "sand", "and", "cat"}));
  return 0;
}
