#include <stdio.h>

typedef struct carOwnerData {
    // values set by user
    char    name[50]; // Name of Cor Owner
    char    phoneNum[9]; // Phone number of CO
    char    Email[50]; // Email of CO
    int     age; // age of CO
    int     postCode; // postcode of CO
    int     price; // Price / h (dkk) of CO
    char    carName[50]; // Name of CO's car
    int     modelYear; // Model year of CO's car
    int     odometer; // kilometers driven by CO's car
    char    transmission; // CO's car's transmission | a = auto, b = manual
    // values set by program
    double  rating[]; // rating of CO
} carOwner;

int main()
{

  carOwner carOwner1;
	char name[30];
  printf("Enter number: ");
  scanf("%d", &carOwner1.price);
  scanf("%c",&temp);
	printf("Enter name: ");
	scanf("%[^\n]", &carOwner1.carName);

  printf("number is: %s\n",carOwner1.carName);

	printf("Name is: %s\n",carOwner1.carName);
	return 0;
}
