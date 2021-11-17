#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct carOwnerData {
    char    name[50];
    char    phoneNum[9];
    char    Email[50];
    char    carType[50];
    int     age;
    int     postalCode;
    double  rating[];
} carOwner;

typedef struct carRenterData {
    char    name[50];
    char    phoneNum[9];
    char    Email[50];
    char    prefCarType[50];
    int     age;
    int     postalCode;
    double  rating[];
} carRenter;

int main(void) {
  srand(time(NULL));  // Seeding the random number generator.

  FILE *output_file_pointer;
  char *str = "Hello";
  char phoneNumber[8];
  int loop;

  output_file_pointer = fopen("users.txt", "a"); // input_file_pointer is set to point at the file users.txt, and append it
  if (output_file_pointer != NULL){      /* File could be opened */
    for (loop = 0; loop < 8; loop++) {
      phoneNumber[loop] = (rand() % 10);
    }


    fprintf(output_file_pointer, "%c ", phoneNumber); // puts us on a new line

  } else {
    printf("Could not open output file. Bye.");
    exit(EXIT_FAILURE);
  }








  return 0;
}
