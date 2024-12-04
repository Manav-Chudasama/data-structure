#include<stdio.h>
#include<conio.h>
#define MAX 100

void merge(int arr[], int left, int mid, int right) {
 int i, j, k;
 int n1, n2;
 int l[MAX], r[MAX];

 n1 = mid - left + 1;
 n2 = right - mid;

 for(i = 0; i < n1; i++) {
  l[i] = arr[left + i];
 }

 for(i = 0; i < n2; i++) {
  r[i] = arr[mid + i + 1];
 }

 i = 0, j = 0, k = left;

 while(i < n1 && j < n2) {
  if(l[i] <= r[j]) {
   arr[k] = l[i];
   i++;
  } else  {
  arr[k] = r[j];
  j++;
  }
  k++;
 }

 while(i < n1) {
  arr[k] = l[i];
  i++;
  k++;
 }

 while(j < n2) {
  arr[k] = r[j];
  j++;
  k++;
 }
}

void mergesort(int arr[], int left, int right) {
 int mid;
 if(left < right) {
  mid = left + (right - left) / 2;

  mergesort(arr, left, mid);
  mergesort(arr, mid + 1, right);

  merge(arr, left, mid, right);
 }
}

void main() {
 int arr[MAX], size, i;
 clrscr();
 printf("\nEnter the size of the array: ");
 scanf("%d", &size);

 printf("\nEnter the  elemensts: ");
 for(i = 0; i < size; i++) {
  scanf("%d", &arr[i]);
 }

 printf("\nSorted: ");
 mergesort(arr, 0, size - 1);
 for(i = 0; i < size; i++) {
  printf("%d ", arr[i]);
 }

 getch();
}