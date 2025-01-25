#include "week_1/013-implement-queue-using-stacks.h"
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
  MyQueue *obj = new MyQueue();
  obj->push(1);
  obj->push(2);
  printf("peek: %d\n", obj->peek());
  obj->pop();
  printf("empty: %d\n", obj->empty());
  printf("peek: %d\n", obj->peek());

  return 0;
}
