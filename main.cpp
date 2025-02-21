#include "050-time-based-key-value-store.h"
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
  TimeMap *obj = new TimeMap();
  obj->set("foo", "bar", 1);
  printf("%s\n", obj->get("foo", 1).c_str());
  printf("%s\n", obj->get("foo", 3).c_str());
  obj->set("foo", "bar2", 4);
  printf("%s\n", obj->get("foo", 4).c_str());
  printf("%s\n", obj->get("foo", 5).c_str());
  return 0;
}
