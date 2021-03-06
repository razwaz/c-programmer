#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE_MAX_EYES 6

void roll_dice(int dice_count, int dice[]);


int main(void) {
  srand(time(NULL));  // Seeding the random number generator.
                      // Do this only once!
  int i, dice_count, loop, throws;

  printf("How many dice to roll?\n");
  scanf(" %d", &dice_count);
  int dice[dice_count]; // creates an array containing 'dice_count' ammount of values

  printf("Ammount of times you want to trow the dice\n");
  scanf(" %d", &throws);

  for (loop = 0 ; loop < throws; loop++) { // all dice get thrown 'throws' times
    roll_dice(dice_count, dice);
  }

  return 0;
}

void roll_dice(int dice_count, int dice[]){ // dice_count = ammount dice thrown, dice[] is the array each dice's value gets assigned to
  int loop;

  printf("You rolled %d dice:\n", dice_count);
  for (loop = 0; loop < dice_count; loop++) {
    dice[loop] = (rand() % DIE_MAX_EYES) + 1;
    printf("%d, ", dice[loop]);
  }
  printf("\n");
}
