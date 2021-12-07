/*
 * Eksamensopgave 2
 * 05-11-2021
 * by Andrzej Piotr Dudko, adudko21@student.aau.dk, SW1
 * A program that plays yatzy with a user input ammount of dice
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DIE_MAX_EYES 6

void input_dice (int *dice_count);
void roll_dice(int dice_count, int dice[]);
// functions for rolling for 1-6
void upper_section(int eyes, int dice_count, int dice[], int points[]);
// functions for the lower section
void one_pair(int dice_count, int dice[], int counter[], int points[]);
void two_pair(int dice_count, int dice[], int counter[], int points[]);
void three_of_kind(int dice_count, int dice[], int counter[], int points[]);
void four_of_kind(int dice_count, int dice[], int counter[], int points[]);
void small_straight(int dice_count, int dice[], int counter[], int points[]);
void large_straight(int dice_count, int dice[], int counter[], int points[]);
void full_house(int dice_count, int dice[], int counter[], int points[]);
void chance(int dice_count, int dice[], int counter[], int points[]);
void yatzy(int dice_count, int dice[], int counter[], int points[]);
// function for q sort to sort my dice largest to lowest
int sort_descend(const void *ip1, const void *ip2);
// function that counts how many of each dice there is
void dice_counter(int dice_count, int dice[], int counter[]);
// general program functions
void score_board(int dice_count, int dice[], int counter[], int points[], int *score, int *bonus);
void yatzy_program(int *dice_count, int counter[], int points[], int *score, int *bonus, bool *run, char *keepPlaying);

int main(void) {
  srand(time(NULL));  // Seeding the random number generator.
                      // Do this only once!
  int dice_count = 0, rounds = 15, score = 0, loop;
  int counter[6];
  int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
  int points[rounds]; // points array initialized to ammount of rounds
  int bonus = 0;
  bool run = true;
  char keepPlaying;

  yatzy_program(&dice_count, counter, points, &score, &bonus, &run, &keepPlaying);
  return 0;
}

void yatzy_program(int *dice_count, int counter[], int points[], int *score, int *bonus, bool *run, char *keepPlaying) {
  while (*run == true) {
    *score = 0;
    input_dice(&*dice_count);
    int dice[*dice_count]; // creates an array containing 'dice_count' ammount of values
    score_board(*dice_count, dice, counter, points, &*score, &*bonus);
    printf("Do you want to play again? (y/n)\n");
    scanf(" %c", &*keepPlaying);
    if (*keepPlaying == 'y') {
      *dice_count = 0;
    } else if (*keepPlaying == 'n') {
      *run = false;
      printf("Thank you for playing, hope to see you again!\n");
    }
  }
}


void score_board(int dice_count, int dice[], int counter[], int points[], int *score, int *bonus) {
  int loop;
  for (loop = 0; loop < 6; loop++) {
    roll_dice(dice_count, dice);
    upper_section(loop+1, dice_count, dice, points);
    printf("Score from rolling for %d: %d\n"
           "--------------------------------------------------------------------------\n", loop+1, points[loop]);
  }

  for (loop = 0; loop < 6; loop++) {
    *score += points[loop];
  }
  printf("Score from upper section: %d\n", *score);
  if (*score > 62) {
    *bonus = 50;
    printf("You scored 63 or more in the upper section, here is 50 bonus points!\n"
           "--------------------------------------------------------------------------\n");
  } else {
    printf("You didnt score 63 or more, no bonus points ):\n"
           "--------------------------------------------------------------------------\n");
  }
  roll_dice(dice_count, dice);
  one_pair(dice_count, dice, counter, points);
  printf("Score for one pair: %d\n"
         "--------------------------------------------------------------------------\n", points[6]);
  roll_dice(dice_count, dice);
  two_pair(dice_count, dice, counter, points);
  printf("Score for two pairs: %d\n"
         "--------------------------------------------------------------------------\n", points[7]);
  roll_dice(dice_count, dice);
  three_of_kind(dice_count, dice, counter, points);
  printf("Score for three of a kind: %d\n"
         "--------------------------------------------------------------------------\n", points[8]);
  roll_dice(dice_count, dice);
  four_of_kind(dice_count, dice, counter, points);
  printf("Score for four of a kind: %d\n"
         "--------------------------------------------------------------------------\n", points[9]);
  roll_dice(dice_count, dice);
  small_straight(dice_count, dice, counter, points);
  printf("Score for small straight: %d\n"
         "--------------------------------------------------------------------------\n", points[10]);
  roll_dice(dice_count, dice);
  large_straight(dice_count, dice, counter, points);
  printf("Score for large straight: %d\n"
         "--------------------------------------------------------------------------\n", points[11]);
  roll_dice(dice_count, dice);
  full_house(dice_count, dice, counter, points);
  printf("Score for full house: %d\n"
         "--------------------------------------------------------------------------\n", points[12]);
  roll_dice(dice_count, dice);
  chance(dice_count, dice, counter, points);
  printf("Score for chance: %d\n"
         "--------------------------------------------------------------------------\n", points[13]);
  roll_dice(dice_count, dice);
  yatzy(dice_count, dice, counter, points);
  printf("Score for yatzy: %d\n"
         "--------------------------------------------------------------------------\n", points[14]);
  for (loop = 6; loop < 15; loop++) {
    *score += points[loop];
  }
  printf("Total score with bonus (if any was acquired): %d\n", *score+*bonus);

}

void roll_dice(int dice_count, int dice[]){ // dice_count = ammount dice thrown, dice[] is the array each dice's value gets assigned to
  int loop;
  for (loop = 0; loop < dice_count; loop++) {
    dice[loop] = (rand() % DIE_MAX_EYES) + 1;
    if (loop == dice_count-1) {   // condition so that the last dice wont have a comma after it
      printf("%d", dice[dice_count-1]);
    } else {
      printf("%d, ", dice[loop]);
    }
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
  int loop;
  points[6] = 0;

  for (loop = 5; loop > -1; loop--) {
    if (counter[loop] > 1 && dice_count - counter[loop] > 2) {
      points[6] = (loop+1)*2;
      loop = -1;
    }
  }
}

void two_pair(int dice_count, int dice[], int counter[], int points[]) {
  dice_counter(dice_count, dice, counter);
  int loop_1, loop_2;
  points[7] = 0;
  for (loop_1 = 5; loop_1 > -1; loop_1--) {
    for (loop_2 = 5; loop_2 > -1; loop_2--) {
      if (counter[loop_1] > 1 && counter[loop_2] > 1 && loop_1 != loop_2 && (dice_count - counter[loop_1] - counter[loop_2]) > 0) {
        points[7] = (loop_1+loop_2+2)*2;
        loop_1 = -1;
        loop_2 = -1;
      }
    }
  }
}

void three_of_kind(int dice_count, int dice[], int counter[], int points[]) {
  dice_counter(dice_count, dice, counter);
  int loop;
  points[8] = 0;
  for (loop = 5; loop > -1; loop--) {
    if (counter[loop] > 2) {
      points[8] = (loop+1)*3;
      loop = -1;
    }
  }
}

void four_of_kind(int dice_count, int dice[], int counter[], int points[]) {
  dice_counter(dice_count, dice, counter);
  int loop;
  points[9] = 0;
  for (loop = 5; loop > -1; loop--) {
    if (counter[loop] > 3) {
      points[9] = (loop+1)*4;
      loop = -1;
    }
  }
}

void small_straight(int dice_count, int dice[], int counter[], int points[]) {
  dice_counter(dice_count, dice, counter);
  points[10] = 0;
  if (counter[4] > 0 && counter[3] > 0 && counter[2] > 0 && counter[1] > 0 && counter[0] > 0)  {
    points[10] = 15;
  }
}

void large_straight(int dice_count, int dice[], int counter[], int points[]) {
  dice_counter(dice_count, dice, counter);
  points[11] = 0;
  if (counter[5] > 0 && counter[4] > 0 && counter[3] > 0 && counter[2] > 0 && counter[1] > 0)  {
    points[11] = 20;
  }
}

void full_house(int dice_count, int dice[], int counter[], int points[]) {
  dice_counter(dice_count, dice, counter);
  int loop_1, loop_2;
  points[12] = 0;
  for (loop_1 = 5; loop_1 > -1; loop_1--) {
    for (loop_2 = 5; loop_2 > -1; loop_2--) {
      if (counter[loop_1] > 2 && dice_count - counter[loop_1] > 1) {
        if (counter[loop_2] > 1 && loop_1 != loop_2) {
          points[12] = (loop_1+1)*3+(loop_2+1)*2;
          loop_1 = -1;
          loop_2 = -1;
        }
      }
    }
  }
}

void chance(int dice_count, int dice[], int counter[], int points[])  {
  dice_counter(dice_count, dice, counter);
  qsort(dice, dice_count, sizeof(int), sort_descend);
  int loop;
  points[13] = 0;
  for (loop = 0; loop < 5; loop++) {
    points[13] += dice[loop];
  }
}

void yatzy(int dice_count, int dice[], int counter[], int points[]) {
  dice_counter(dice_count, dice, counter);
  points[14] = 0;
  int loop;
  for (loop = 0; loop < 5; loop++) {
    if (counter[loop] > 4) {
      points[14] = 50;
      loop = 5;
    }
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
