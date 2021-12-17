/*
 * Eksamensopgave 3
 * 17-12-2021
 * by Andrzej Piotr Dudko, adudko21@student.aau.dk, SW1
 * A program that sorts a textfile containing match data and returns
 * a leaderboard with team names, points, goals for and goals agaist
 * through standard output.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATCHES 132  // number of matches
#define TEAMS 12 // number of teams

enum teamNames {AaB, ACH, AGF, BIF, FCK, FCM, FCN, LBK, OB, RFC, SDR, VB};

typedef struct match {
  char weekday[4];
  char date[6];
  char time[6];
  char homeTeam[4];
  char awayTeam[4];
  int homeScore;
  int awayScore;
  int spectators;
} match;

typedef struct team {
  char teamName[4];
  int points;
  int goalsFor;
  int goalsAgainst;
} team;

void setupMatches(struct match match[]);
void setupTeams (struct team team[]);
void results (struct team team[]);
void sortTeams (struct team team[]);
void teamsSum (struct match match[], struct team team[]);
void teamHomeSum (struct match match[], struct team team[], int name, int i);
void teamAwaySum (struct match match[], struct team team[], int name, int i);

int main(void) {
  match match[MATCHES];
  team team[TEAMS];

  setupMatches(match);
  teamsSum(match, team);
  sortTeams(team);
  results(team);

  return 0;
}

void setupMatches(struct match match[]) {
  FILE *ifp;
  int i, j, prevI;
  char line[60];

  ifp = fopen("kampe-2020-2021.txt", "r");

  if (ifp != NULL){
    for (j = 0; j < MATCHES; j++) {
      i = 0;
      if (fgets(line, 60, ifp) != NULL) {
        while(i < 3) {
          match[j].weekday[i] = line[i];
          i++;
        }
        match[j].weekday[i] = '\0';

        i = 8;
        while(i < 13) {
          match[j].date[i-8] = line[i];
          i++;
        }
        match[j].date[i-8] = '\0';

        i = 14;
        while(i < 19) {
          match[j].time[i-14] = line[i];
          i++;
        }
        match[j].time[i-14] = '\0';

        i = 24;
        while(line[i] != ' ') {
          match[j].homeTeam[i-24] = line[i];
          i++;
        }
        match[j].homeTeam[i-24] = '\0';

        i += 3;
        prevI = i; // used to avoid conflict with two letter team names
        while(line[i] != ' ') {
          match[j].awayTeam[i-prevI] = line[i];
          i++;
        }
        match[j].awayTeam[i-prevI] = '\0';

        match[j].homeScore = line[38] - '0';
        match[j].awayScore = line[42] - '0';

        i = 48;
        while (line[i] != ' ') {
          i++;
        }
        // char[] is made here as atoi() will crash if the array contains more
        // chars than the number of digits the spectator number has
        char spectatorNr[i-48];
        i = 48;
        while (line[i] != ' ') {
          spectatorNr[i-48] = line[i];
          i++;
        }
        spectatorNr[i] = '\0';
        match[j].spectators = atoi(spectatorNr);
      }
    }
    fclose(ifp);
  } else {
    printf("Could not open input file. Bye.");
    exit(EXIT_FAILURE);
  }
}

void results (struct team team[]) { // prints the sorted teams in the console
  int i;
  for (i = 0; i < TEAMS; i++) {
    if (strcmp(team[i].teamName, "OB") == 0 || strcmp(team[i].teamName, "VB") == 0) {
      printf("%s      %d     %d     %d\n", team[i].teamName, team[i].points, team[i].goalsFor, team[i].goalsAgainst);
    } else {
      printf("%s     %d     %d     %d\n", team[i].teamName, team[i].points, team[i].goalsFor, team[i].goalsAgainst);
    }
  }
}

void sortTeams(struct team team[]) { // sorts teams in descending order primarly by points and secondarily by goal differential
  int i, j;
  struct team temp;

  for (i = 0; i < TEAMS; i++) {
    for (j = 0; j < (TEAMS - 1 - i); j++) { // -1 - i, they indicate that the teams with an index of 'TEAMS - 1 -i' and greater is sorted
      if (team[j].points == team[j+1].points) {
        if (team[j].goalsFor - team[j].goalsAgainst < team[j+1].goalsFor - team[j+1].goalsAgainst) {
          temp = team[j];
          team[j] = team[j+1];
          team[j+1] = temp;
        }
      } else if (team[j].points < team[j+1].points) {
        temp = team[j];
        team[j] = team[j+1];
        team[j+1] = temp;
      }
    }
  }
}

void teamsSum (struct match match[], struct team team[]) { // assigns 'points', 'goals for' and 'goals against' for every team
  int i,j;
  int k = 0;
  setupTeams(team);

  for (i = 0; i < MATCHES; i++) {
    for (j = 0; j < TEAMS; j++) {
      if (strcmp(match[i].homeTeam, team[j].teamName) == 0) {
        teamHomeSum(match, team, j, i);
      } else if (strcmp(match[i].awayTeam, team[j].teamName) == 0) {
        teamAwaySum(match, team, j, i);
      }
    }
  }
}

void setupTeams (struct team team[]) { // assigns team names and sets all ints to 0
  int i;

  strcpy(team[AaB].teamName, "AaB");
  strcpy(team[ACH].teamName, "ACH");
  strcpy(team[AGF].teamName, "AGF");
  strcpy(team[BIF].teamName, "BIF");
  strcpy(team[FCK].teamName, "FCK");
  strcpy(team[FCM].teamName, "FCM");
  strcpy(team[FCN].teamName, "FCN");
  strcpy(team[LBK].teamName, "LBK");
  strcpy(team[OB].teamName, "OB");
  strcpy(team[RFC].teamName, "RFC");
  strcpy(team[SDR].teamName, "SDR");
  strcpy(team[VB].teamName, "VB");

  for (i = AaB; i < TEAMS; i++) {
    team[i].points = 0;
    team[i].goalsFor = 0;
    team[i].goalsAgainst = 0;
  }
}

void teamHomeSum (struct match match[], struct team team[], int name, int i) {
  team[name].goalsFor += match[i].homeScore;
  team[name].goalsAgainst += match[i].awayScore;
  if (match[i].homeScore > match[i].awayScore) {
    team[name].points += 3;
  } else if (match[i].homeScore == match[i].awayScore) {
    team[name].points += 1;
  }
}

void teamAwaySum (struct match match[], struct team team[], int name, int i) {
  team[name].goalsFor += match[i].awayScore;
  team[name].goalsAgainst += match[i].homeScore;
  if (match[i].homeScore < match[i].awayScore) {
    team[name].points += 3;
  } else if (match[i].homeScore == match[i].awayScore) {
    team[name].points += 1;
  }
}
