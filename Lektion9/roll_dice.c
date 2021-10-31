#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE_MAX_EYES 6

int roll_dice();


int main(void) {
  int i;
  int dice_count = 5;
  int loop;
  srand(time(NULL));  // Seeding the random number generator.
                      // Do this only once!

  scanf(" %d\n", &dice_count);
  int dice[dice_count];

  for (loop = 0; loop < dice_count; loop++) {
    dice[loop] = roll_dice();
    printf(" %lf\n", dice[loop]);
  }

  printf ("%lf\n", dice[1]);

  return 0;
}

int roll_dice(){
  int dice;
  dice = (rand() % DIE_MAX_EYES) + 1;
  return dice;
}
