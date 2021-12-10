#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATCHES 132

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

void setupTeams (struct team team[]);
void results (struct team team[]);
void teamRanking (struct team team[]);
void teamsSum (struct match match[], struct team team[]);
void teamHomeSum (struct match match[], struct team team[], int name, int i);
void teamAwaySum (struct match match[], struct team team[], int name, int i);

int main(void) {
  match match[MATCHES];
  team team[12];

  FILE *input_file_pointer;

  int j = 0;
  int i = 0;
  char line[60];

  input_file_pointer = fopen("kampe-2020-2021.txt", "r");
  if (input_file_pointer != NULL){
    for (j = 0; j < MATCHES; j++) {
      if (fgets(line, 60, input_file_pointer) != NULL) {
        i = 0;
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
        int prevI = i; // used to avoid conflict with two letter team names
        while(line[i] != ' ') {
          match[j].awayTeam[i-prevI] = line[i];
          i++;
        }
        match[j].awayTeam[i-prevI] = '\0';

        match[j].homeScore = line[38] - '0';
        match[j].awayScore = line[42] - '0';

        char spectatorNr[5];
        i = 48;
        while (line[i] != ' ') {
          spectatorNr[i-48] = line[i];
          i++;
        }
        match[j].spectators = atoi(spectatorNr);
      }
      /* print for debugging
      printf("Match %d --------------------------------\n", j+1);
      printf("Weekday: %s \n", match[j].weekday);
      printf("date: %s \n", match[j].date);
      printf("time: %s \n", match[j].time);
      printf("home team: %s \n", match[j].homeTeam);
      printf("away team: %s \n", match[j].awayTeam);
      printf("home score: %d \n", match[j].homeScore);
      printf("away score: %d \n", match[j].awayScore);
      printf("spectators: %d \n", match[j].spectators);
      */

    }
    fclose(input_file_pointer);
  } else {
    printf("Could not open input file. Bye.");
    exit(EXIT_FAILURE);
  }

  teamsSum(match, team);
  teamRanking(team);
  results(team);

  return 0;
}

void results (struct team team[]) {
  int i;
  for (i = 0; i < 12; i++) {
    if (strcmp(team[i].teamName, "OB") == 0 || strcmp(team[i].teamName, "VB") == 0) {
      printf("%s      %d     %d     %d\n", team[i].teamName, team[i].points, team[i].goalsFor, team[i].goalsAgainst);
    } else {
      printf("%s     %d     %d     %d\n", team[i].teamName, team[i].points, team[i].goalsFor, team[i].goalsAgainst);
    }
  }
}

void teamRanking (struct team team[]) {
  int i, j;
  struct team temp;

  for (i = 0; i < 12; i++) {
    for (j = 0; j < (12 - 1 - i); j++) {
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

void teamsSum (struct match match[], struct team team[]) {
  int i;
  setupTeams(team);

  for (i = 0; i < MATCHES; i++) {
    // Point calculation for home teams
    if (strcmp(match[i].homeTeam, "AaB") == 0) {
      teamHomeSum(match, team, AaB, i);
    } else if (strcmp(match[i].homeTeam, "ACH") == 0) {
      teamHomeSum(match, team, ACH, i);
    }else if (strcmp(match[i].homeTeam, "AGF") == 0) {
      teamHomeSum(match, team, AGF, i);
    }else if (strcmp(match[i].homeTeam, "BIF") == 0) {
      teamHomeSum(match, team, BIF, i);
    }else if (strcmp(match[i].homeTeam, "FCK") == 0) {
      teamHomeSum(match, team, FCK, i);
    }else if (strcmp(match[i].homeTeam, "FCM") == 0) {
      teamHomeSum(match, team, FCM, i);
    }else if (strcmp(match[i].homeTeam, "FCN") == 0) {
      teamHomeSum(match, team, FCN, i);
    }else if (strcmp(match[i].homeTeam, "LBK") == 0) {
      teamHomeSum(match, team, LBK, i);
    }else if (strcmp(match[i].homeTeam, "OB") == 0) {
      teamHomeSum(match, team, OB, i);
    }else if (strcmp(match[i].homeTeam, "RFC") == 0) {
      teamHomeSum(match, team, RFC, i);
    }else if (strcmp(match[i].homeTeam, "SDR") == 0) {
      teamHomeSum(match, team, SDR, i);
    }else if (strcmp(match[i].homeTeam, "VB") == 0) {
      teamHomeSum(match, team, VB, i);
    }
    // Point calculation for away teams
    if (strcmp(match[i].awayTeam, "AaB") == 0) {
      teamAwaySum(match, team, AaB, i);
    } else if (strcmp(match[i].awayTeam, "ACH") == 0) {
      teamAwaySum(match, team, ACH, i);
    }else if (strcmp(match[i].awayTeam, "AGF") == 0) {
      teamAwaySum(match, team, AGF, i);
    }else if (strcmp(match[i].awayTeam, "BIF") == 0) {
      teamAwaySum(match, team, BIF, i);
    }else if (strcmp(match[i].awayTeam, "FCK") == 0) {
      teamAwaySum(match, team, FCK, i);
    }else if (strcmp(match[i].awayTeam, "FCM") == 0) {
      teamAwaySum(match, team, FCM, i);
    }else if (strcmp(match[i].awayTeam, "FCN") == 0) {
      teamAwaySum(match, team, FCN, i);
    }else if (strcmp(match[i].awayTeam, "LBK") == 0) {
      teamAwaySum(match, team, LBK, i);
    }else if (strcmp(match[i].awayTeam, "OB") == 0) {
      teamAwaySum(match, team, OB, i);
    }else if (strcmp(match[i].awayTeam, "RFC") == 0) {
      teamAwaySum(match, team, RFC, i);
    }else if (strcmp(match[i].awayTeam, "SDR") == 0) {
      teamAwaySum(match, team, SDR, i);
    }else if (strcmp(match[i].awayTeam, "VB") == 0) {
      teamAwaySum(match, team, VB, i);
    }
  }
}


void setupTeams (struct team team[]) {
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

  for (i = AaB; i < VB; i++) {
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
