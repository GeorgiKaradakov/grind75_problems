#include "035-clone-graph.h"
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
  print_mat(to_edge_list(
      Solution().cloneGraph(from_adj({{1, 2}, {1, 4}, {2, 3}, {4, 3}}, 1))));

  print_mat(to_edge_list(Solution().cloneGraph(from_adj({}, 1))));
  return 0;
}
