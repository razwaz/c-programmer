#include <stdio.h>

int main(void) {

  int v = 7;
  int *pv = &v;

  *pv = 8;

  printf("v = %d\n", v);
  printf("pv points at %d\n", *pv);
  printf("pv is the pointer %x\n", pv);

  return 0;
}
