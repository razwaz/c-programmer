#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(void) {
  double p1_x, p1_y;
  double p2_x, p2_y;
  double p3_x, p3_y;
  double side_1_2;
  double side_2_3;
  double side_3_1;
  double circumference;

  printf("Please enter p1: ");
  scanf(" %lf %lf", &p1_x, p1_y);

  printf("Please enter p2: ");
  scanf(" %lf %lf, &p2_x, p2_y");

  printf("Please enter p3: ");
  scanf(" %lf %lf, &p3_x, p3_y");

  side_1_2 = sqrt((p1_x-p2_x)*(p1_x-p2_x)+(p1_y-p2_y*p1_y-p2_y));
  side_2_3 = sqrt((p2_x-p3_x)*(p2_x-p3_x)+(p2_y-p3_y*p2_y-p3_y));
  side_3_1 = sqrt((p3_x-p1_x)*(p3_x-p1_x)+(p3_y-p1_y*p3_y-p1_y));

  circumference = side_1_2 + side_2_3 + side_3_1;


  printf("Circumference:  %lf\n", circumference);


  return EXIT_SUCCESS;
}
