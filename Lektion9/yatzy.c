/*
 * Eksamensopgave 2
 * 05-11-2021
 * by Andrzej Piotr Dudko, adudko21@student.aau.dk, SW1
 * A program that plays yatzy with a user input ammount of dice
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE_MAX_EYES 6

void input_dice (int *dice_count);
void roll_dice(int dice_count, int dice[]);

void upper_section(int eyes, int dice_count, int dice[], int points[]);

void one_pair(int dice_count, int dice[], int counter[], int points[]);

int sort_ascend(const void *ip1, const void *ip2);
int sort_descend(const void *ip1, const void *ip2);

void dice_counter(int dice_count, int dice[], int counter[]);


int main(void) {
  srand(time(NULL));  // Seeding the random number generator.
                      // Do this only once!
  int dice_count = 0, rounds = 15, score = 0, loop;
  int counter[6];
  int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
  int points[rounds]; // points array initialized to ammount of rounds
  input_dice(&dice_count);
  int dice[dice_count]; // creates an array containing 'dice_count' ammount of values



  for (loop = 1; loop < 7; loop++){
    roll_dice(dice_count, dice);
    upper_section(loop, dice_count, dice, points);
    printf("Score: %d\n", points[loop-1]);
  }

  for (loop = 0; loop < 6; loop++) {
    score = score+points[loop];
  }
  printf("Total Score: %d\n", score);

  qsort(dice, dice_count, sizeof(int), sort_descend);







  one_pair(dice_count, dice, counter, points);
  printf("Score for one pair: %d\n", points[6]);
  //printf("you rolled %d 4's\n", counter[3]);








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


void input_dice (int *dice_count) {  // this function asks the user to input an ammount of dice greater than 4
  printf("How many dice to roll? ");
  while (*dice_count < 5) {
    printf("Please input an integer larger than 4\n");
    scanf(" %d", &*dice_count);
  }
}

void upper_section(int eyes, int dice_count, int dice[], int points[]) {
  points[eyes-1] = 0; // the -1 on eyes is because the first value in an array is adressed as points[0]
  int maxpoints = 0, loop;
  for (loop = 0; loop < dice_count; loop++) {
    if (dice[loop] == eyes && maxpoints < 5) {
      points[eyes-1] += eyes;
      maxpoints++;
    } else if (maxpoints == 5) {
      loop = dice_count;
    }
  }
}


void one_pair(int dice_count, int dice[], int counter[], int points[]) {
  dice_counter(dice_count, dice, counter);
  if (counter[5] > 1 && dice_count - counter[5] > 2) {
    points[6] = 12;
  } else if (counter[4] > 1 && dice_count - counter[4] > 2) {
    points[6] = 10;
  } else if (counter[3] > 1 && dice_count - counter[3] > 2) {
    points[6] = 8;
  } else if (counter[2] > 1 && dice_count - counter[2] > 2) {
    points[6] = 6;
  } else if (counter[1] > 1 && dice_count - counter[1] > 2) {
    points[6] = 4;
  } else if (counter[0] > 1 && dice_count - counter[0] > 2) {
    points[6] = 2;
  } else {
    points[6] = 0;
  }
}

void dice_counter(int dice_count, int dice[], int counter[]) {
  int loop;
  for (loop = 0; loop < 6; loop++) {
    counter[loop] = 0;
  }
  for (loop = 0; loop < dice_count; loop++) {
    if(dice[loop] == 1) {
      counter[0]++;
    } else if (dice[loop] == 2) {
      counter[1]++;
    } else if(dice[loop] == 3) {
      counter[2]++;
    } else if (dice[loop] == 4) {
      counter[3]++;
    } else if(dice[loop] == 5) {
      counter[4]++;
    } else if (dice[loop] == 6) {
      counter[5]++;
    }
  }
}


int sort_ascend(const void *ip1, const void *ip2){
  int result;
  int *ipi1 = (int *)ip1,
      *ipi2 = (int *) ip2;

  if (*ipi1 < *ipi2)
     result = -1;
  else if (*ipi1 > *ipi2)
     result = 1;
  else
     result = 0;

  return result;
}

int sort_descend(const void *ip1, const void *ip2){
  int result;
  int *ipi1 = (int *)ip1,
      *ipi2 = (int *) ip2;

  if (*ipi1 < *ipi2)
     result = 1;
  else if (*ipi1 > *ipi2)
     result = -1;
  else
     result = 0;

  return result;
}
