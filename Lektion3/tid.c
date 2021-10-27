// by Andrzej Piotr Dudko, E21 SW1, AAU
//
// This program requests the user to input an integer of seconds
// that the program then converts to weeks, days, hours, minutes and seconds.

#include <stdio.h>
#define m 60        // I define values for how many seconds a minute, hour,
#define h 3600      // day and week has for easy use.
#define d 86400
#define w 604800

int main(void) {
  int s,        // Initialisation of s, sec, min, hour, day and week.
  sec = 0,      // s is not specified as its dictated by user input later,
  min = 0,      // while the other values would end up breaking the output
  hour = 0,     // if user input made any of these values stay unassigned
  day = 0,      // past the if statements like the one on l18.
  week = 0;

  printf("Please enter ammount of seconds: ");
  scanf(" %d", &s);  // Program asks user to input an integer and assigns it

  week = s / w;
  day = (s % w)/d;
  hour = (s % d)/h;
  min = (s % h)/m;
  sec = s % m;

  if (week == 1) {
    printf("%d week, ", week);
  } else if (week > 1){
    printf("%d weeks, ", week);
  }

  if (day == 1) {
    printf("%d day, ", day);
  } else if (day > 1){
    printf("%d days, ", day);
  }

  if (hour == 1) {
    printf("%d hour, ", hour);
  } else if (hour > 1){
    printf("%d hours, ", hour);
  }

  if (min == 1) {
    printf("%d minute, ", min);
  } else if (min > 1){
    printf("%d minutes, ", min);
  }

  if (sec == 1) {
    printf("and %d second.\n", sec);  // The last prints end with a \n to make a
  } else if (sec > 1){                            // new line in the terminal
    printf("and %d seconds.\n", sec);
  } else {
    printf("\n");
  }

  return 0;
}
