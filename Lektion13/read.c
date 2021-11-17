#include <stdio.h>
#include <stdlib.h>
#define MAX_STR_LEN 100

int main(void) {
  srand(time(NULL));  // Seeding the random number generator.

  FILE *input_file_pointer;
  char str[MAX_STR_LEN];
  int ch;
  int i = 0;

  input_file_pointer = fopen("users.txt", "r");


  if (input_file_pointer != NULL){        /* File could be opened */
    while ((ch = fgetc(input_file_pointer)) != EOF){
      str[i] = ch;
      i++;
    }
    str[i] = '\0';

    printf("Read from file: %s\n", str);

    fclose(input_file_pointer);
  }
  else{
    printf("Could not open input file. Bye.");
    exit(EXIT_FAILURE);
  }



  return 0;
}
