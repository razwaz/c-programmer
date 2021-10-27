#include <stdio.h>

int main(void) {

  int x;

  printf("Enter an integer: ");
  scanf("%d", &x);

  printf("The sign of %d is %s\n\n",
         x,
         (x < 0) ? "negative" : ((x == 0) ? "neutral" : "positive")
        );

  return 0;
}
