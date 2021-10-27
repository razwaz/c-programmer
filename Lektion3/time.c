// by Andrzej Piotr Dudko, E21 SW1, AAU
//
// This program requests the user to input an integer of seconds
// that the program then converts to weeks, days, hours, minutes and seconds.
// This is the seconds version of the program with additional formatting done.

#include <stdio.h>
#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR 3600
#define SECONDS_PER_DAY 86400
#define SECONDS_PER_WEEK 604800

int main(void) {
  int s,
  sec = 0,
  min = 0,
  hour = 0,
  day = 0,
  week = 0;

  printf("Please enter ammount of seconds: ");
  scanf(" %d", &s);

  week = s / SECONDS_PER_WEEK;
  day = (s % SECONDS_PER_WEEK) / SECONDS_PER_DAY;
  hour = (s % SECONDS_PER_DAY) / SECONDS_PER_HOUR;
  min = (s % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
  sec = s % SECONDS_PER_MINUTE;

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
    printf("%d minute", min);
  } else if (min > 1){
    printf("%d minutes", min);
  }

  if (sec > 0) {   // These two if statements are to fix formatting issues
    if (week > 0 || day > 0 || hour > 0 || min > 0 ) {
      printf(" and ");
    }
  } else {
    printf(".");
  }

  if (sec == 1) {
    printf("%d second.\n", sec);
  } else if (sec > 1){
    printf("%d seconds.\n", sec);
  } else {
    printf("\n");
  }
  return 0;
}
