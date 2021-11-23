#include <stdio.h>
#include <stdlib.h>

void Merge(int L[], int start, int end, int mid);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);

int main(void){
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 };
  int L_size = sizeof(L) / sizeof(L[0]);

  printf("Given list \n");
  printList(L, L_size);

  MergeSort(L, 0, L_size - 1);

  printf("The sorted list \n");
  printList(L, L_size);
  return 0;
}

void Merge(int L[], int start, int end, int mid){
/*Here goes your code*/
}

void MergeSort(int L[], int start, int end){
  /*Here goes your code as well*/
}

void printList(int L[], int size){
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", L[i]);
  printf("\n");
}
