#include <stdio.h>

int main(void) {
  int grade7;

  /* Prompt for input */
  printf("Enter Danish 7 step grade: ");
  scanf("%d", &grade7);

  /* Find and print the corresponding ECTS grade */
  printf("The corresponding ECTS grade is: ");
  switch(grade7){
    case 12:
      printf("A"); break;
    case 10:
      printf("B"); break;
    case 7:
      printf("C"); break;
    case 4:
      printf("D"); break;
    case 2:
      printf("E"); break;
    case 0:
      printf("Fx"); break;
    case -3:
      printf("F"); break;
    default:
      printf("Illegal");
  }
  printf("\n");

  return 0;
}
