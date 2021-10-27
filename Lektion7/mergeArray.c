/*
 * Afleveringsopgave 6
 * by Andrzej Piotr Dudko, adudko21@student.aau.dk, SW1
 * A program that merges two arrays into one, under the assumption that the
 * arrays are sorted
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_ARRAY1 7
#define SIZE_OF_ARRAY2 5

int main(void) {
  const double array1[SIZE_OF_ARRAY1] = {7.8, 8.8, 17.0, 23.1, 27.8, 30.1, 50.0};
  const double array2[SIZE_OF_ARRAY2] = {-7.0, 8.8, 17.0, 18.1, 27.8};

  double combine[SIZE_OF_ARRAY1 + SIZE_OF_ARRAY2];
  int pointer1 = 0, pointer2 = 0, pointer3 = 0, loop;

  while (pointer3 < SIZE_OF_ARRAY1 + SIZE_OF_ARRAY2) {
    if (pointer1 <= SIZE_OF_ARRAY1 && pointer2 <= SIZE_OF_ARRAY2) {  // if both the pointers for array1 and 2 are valid
      if (array1[pointer1] < array2[pointer2]) {  // if the array1 value is smaller than array2
        combine[pointer3] = array1[pointer1];     // set the value of combine to the value of array1
        pointer1++;
      } else {
        combine[pointer3] = array2[pointer2];
        pointer2++;
      }
    }

    if (pointer1 > SIZE_OF_ARRAY1 && pointer2 <= SIZE_OF_ARRAY2) {  // if array2 is still valid and array1 has been exhausted
      combine[pointer3] = array2[pointer2];                         // set the value of array2 to combine
      pointer2++;
    } else if (pointer2 > SIZE_OF_ARRAY2 && pointer1 <= SIZE_OF_ARRAY1) {
      combine[pointer3] = array1[pointer1];
      pointer1++;
    }
    pointer3++;
  }

  // for loop that prints the merged array
  for (loop = 0; loop < SIZE_OF_ARRAY1+SIZE_OF_ARRAY2; loop++) {
    if (loop == 0) {
      printf("The arrays were merged to:\n");
    }

    printf(" %lf\n", combine[loop]);
    }

  return 0;
}
