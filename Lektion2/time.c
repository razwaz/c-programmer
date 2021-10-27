// by Andrzej Piotr Dudko, E21 SW1, AAU
//
// This program request the user to input an integer of seconds
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
  if (s >= w) {      // to the integer s
  week = s / w;      // If user input is high enough for the seconds to be at least
                     // a week, divide the 'user input' by 'seconds in a week' to
  }                  //  get the ammount of weeks.

  if (s >= d) {      // If user input is high enough for the seconds to be at least
    day = (s % w)/d; // a day, modulo the 'user input' by 'seconds in a week'.
  }                  // The number you get is the leftover seconds, which we
                     // divide by 'seconds in a day' to get the ammount of days.
  if (s >= h) {      // This is repeated to get hours, minutes and seconds
    hour = (s % d)/h;
  }

  if (s >= m) {
    min = (s % h)/m;
  }

  if (s != 0) {   // The if statement is changed to ignore all inputs that are 0
    sec = s % m;  // to prevent the program from trying to modulo
  }               // 0 by 'seconds in a minute'

  if (week == 1) {               // These if statements are for determining
    printf("%d week, ", week);   // whether the unit should be written in
  } else {                       // singular or plural, anything other than one
    printf("%d weeks, ", week);  // is written in plural
  }

  if (day == 1) {
    printf("%d day, ", day);
  } else {
    printf("%d days, ", day);
  }

  if (hour == 1) {
    printf("%d hour, ", hour);
  } else {
    printf("%d hours, ", hour);
  }

  if (min == 1) {
    printf("%d minute, ", min);
  } else {
    printf("%d minutes, ", min);
  }

  if (sec == 1) {
    printf("and %d second.\n", sec);  // The last prints end with a \n to make a
  } else {                            // new line in the terminal
    printf("and %d seconds.\n", sec);
  }

  return 0;
}
