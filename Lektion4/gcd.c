// by Andrzej Piotr Dudko, E21 SW1, AAU
// 25-09-2021
// A program that finds the Greatest Common Divisior between two positive ints.

#include <stdio.h>

int main(void) {
  int num1,
  num2,
  skip,
  i;

  printf("Please input two positive integers separated by a space: ");
  scanf("%d %d", &num1, &num2);

  while (num1 < 1 || num2 < 1) {
    printf("Please input two positive integers - Try again: ");
    scanf("%d %d", &num1, &num2);
  }

  if (num1 <= num2){ // optimization for when one number is much larger
    skip = num1;
  } else {
    skip = num2;
  }

  for (i = skip; i > 0; --i) {
    if (num1%i == 0 && num2%i == 0) { // A number % by its GCD is always == 0
      printf("The greatest common divisor is: %d\n", i);
      i = 0;  // Done, exit loop
    }
  }
  return 0;
}
