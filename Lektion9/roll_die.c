#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE_MAX_EYES 6

int roll_die(void){
  return (rand() % DIE_MAX_EYES) + 1;
}

int main(void) {
  int i;

  srand(time(NULL));  // Seeding the random number generator.
                      // Do this only once!

  for(i = 1; i <= 10; i++)
    printf("The die shows: %d\n", roll_die());

  return 0;
}
