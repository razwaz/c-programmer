#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE_MAX_EYES 6

void roll_multiple_dice(int *dice_count, int *dice[(int)dice_count]);


int main(void) {
  int i;
  int dice_count = 5;

  scanf("%d\n", &dice_count);
  int dice[dice_count];




  srand(time(NULL));  // Seeding the random number generator.
                      // Do this only once!
/*
  for(i = 1; i <= 10; i++)
    printf("The die shows: %d\n", roll_die());
    */
    roll_multiple_dice(&dice_count, &dice[(int)&dice_count]);

  return 0;
}

void roll_multiple_dice(int *dice_count, int *dice[(int)*dice_count]){
  int loop;

  for (loop = 0; loop < *dice_count; loop++) {
    *dice[loop] = (rand() % DIE_MAX_EYES) + 1;
    }
}
