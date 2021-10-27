// to run this program use 'gcc test-primes.c primes.o -o primes'
// if you want to update primes.o or .h run 'gcc -c primes.c'

#include "primes.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

int primeNr = 1;
int prime = 1;

int main(void) {
  while (prime <= 100) {
    if (is_prime(primeNr) == 1) {
      printf("Prime %d: %d\n", prime, primeNr);
      prime++;
    }
    primeNr++;
  }
  return 0;
}
