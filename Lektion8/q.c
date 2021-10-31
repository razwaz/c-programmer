#include <stdio.h>
#include <stdlib.h>

double g = 5.6;
void f(double g){
  printf("%fl", g);
}

int main(void) {
  int d = 7;
  char c = 'a';
  f(2.124);

  return EXIT_SUCCESS;
}
