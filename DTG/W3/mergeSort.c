/* Merge sort program made from the pseudo code from DTG workshop 3.
 * The program is a great example of recursive functions.
 * The program has a bunch of printf's to show how the program works and
 * to make debugging much less of a hassle.
 */

#include <stdio.h>
#include <stdlib.h>

void Merge(int L[], int start, int end, int mid);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);

int main(void){
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 };
  printf("L[0]=%d\n",L[0]);
  int L_size = sizeof(L) / sizeof(L[0]);

  printf("Given list \n");
  printList(L, L_size);

  MergeSort(L, 0, L_size - 1);

  printf("-------------------------------------\n");
  printf("The sorted list \n");
  printList(L, L_size);
  printf("-------------------------------------\n");
  return 0;
}

void Merge(int L[], int start, int end, int mid){
  /*Here goes your code*/
  int i, j, k;
  printf("-------------------------------------\n");
  printf("Start: %d, Mid: %d, End: %d\n", start, mid, end);

  int L1[mid-start+1];
  int L2[end-mid];

  for (i = 0; i < mid-start+1; i++) {
    L1[i] = L[start+i];
  }
  for (i = 0; i <= end-mid; i++) {
    L2[i] = L[mid+i+1];
  }

  printf("L: ");
  printList(L, 10);
  printf("L1: ");
  printList(L1, mid-start+1);
  printf("L2: ");
  printList(L2, end-mid);

  i = 0;
  j = 0;

  do {
    if (L1[i] <= L2[j]) {
      L[start+i+j] = L1[i];
      i++;

    } else {
      L[start+i+j] = L2[j];
      j++;
    }
  } while (i < (mid - start + 1) && j < (end - mid));

  if (i == (mid - start+1)) {
    for (k = j; k < (end - mid); k++){
      L[start+i+k] = L2[k];
    }
  } else {
    for (k = i; k < (mid - start + 1); k++) {
      L[start+j+k] = L1[k];
    }
  }
}

void MergeSort(int L[], int start, int end){
  /*Here goes your code as well*/
  int m;
  if (start < end) {
    m = (end+start)/2;
    MergeSort(L, start, m);
    MergeSort(L, m+1, end);
    Merge(L, start, end, m);
  }
}

void printList(int L[], int size){
  int i;
  for (i = 0; i < size; i++)
  printf("%d ", L[i]);
  printf("\n");
}
