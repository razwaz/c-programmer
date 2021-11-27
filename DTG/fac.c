/* An example of a recursive algorithm that returns a factorial
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


unsigned long Factorial(unsigned long n);

void main() {
  unsigned long n;
  scanf("%d", &n);
  printf("result is: %d \n", Factorial(n));

}

unsigned long Factorial(unsigned long n) {
  if (n == 0) {
    return 1;
  } else {
    /* factorial gets called to calculate n-1, and then that will call itself
     again (n-1-1) and so on until n = 0 where the function will return 1 */
    n = n * Factorial(n-1);
    return n;
  }
}
