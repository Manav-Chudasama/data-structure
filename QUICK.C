#include<stdio.h>
#include<conio.h>

void swap(int *a, int *b) {
 int temp;
 temp = *a;
 *a = *b;
 *b = temp;
}
int partition(int arr[], int low, int high) {
 int p = arr[low];
 int i = low, j = high;

 while(i < j) {
  while(arr[i] <= p && i <= j - 1) {
   i++;
  }
  while(arr[j] > p && j >= i + 1) {
   j--;
  }
  if(i < j) {
   swap(&arr[i], &arr[j]);
  }
 }
 swap(&arr[low], &arr[j]);

 return j;
}

void quicksort(int arr[], int low, int high) {
 int pi;
 if(low < high) {
  pi = partition(arr, low, high);

  quicksort(arr, low, pi - 1);
  quicksort(arr, pi + 1, high);
 }
}

void main() {
 int arr[100],size, i;
 clrscr();
 printf("\nEnter the size of the array: ");
 scanf("%d", &size);

 printf("\nEnter the elements: ");
 for(i = 0; i < size; i++) {
  scanf("%d", &arr[i]);
 }

 quicksort(arr, 0, size - 1);

 for(i = 0; i < size; i++) {
  printf("%d ", arr[i]);
 }
 getch();
}