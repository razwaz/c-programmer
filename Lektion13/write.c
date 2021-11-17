#include <stdio.h>
#include <stdlib.h>


int main(void) {

  FILE *output_file_pointer;
  char *str = "Hello";

  output_file_pointer = fopen("first-file.txt", "a");

  if (output_file_pointer != NULL){      /* File could be opened */
    while (*str != '\0'){
      fputc(*str, output_file_pointer);
      str++;
    }

    fclose(output_file_pointer);
  }
  else{
    printf("Could not open output file. Bye.");
    exit(EXIT_FAILURE);
  }

  return 0;
}
