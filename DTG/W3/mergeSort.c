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
  int i = 0;
  int j = 0;
  int k;
  printf("Start: %d, Mid: %d, End: %d\n", start, mid, end);
  int L1[end];
  int L2[end];
  for (i = start; i <= mid; i++) {
    L1[i-start] = L[i];
  }
  for (i = mid; i <= end; i++) {
    L2[i-mid] = L[i+1];
  }
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
  } while (i < (mid - start) && j < (end - mid));

  if (i = mid - start+1) {
    for (k = j; k < end - mid - 1; k++){
      L[start+i+k] = L2[k];
    }
  } else {
    for (k = i; k < mid - start; k++) {
      L[start+j+k] = L1[k];
    }
  }



  printf("L1: ");
  printList(L1, mid);
  printf("L2: ");
  printList(L2, end);

}

void MergeSort(int L[], int start, int end){
  int m = 0;
  /*Here goes your code as well*/
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
