#include <stdio.h>

int sumofarr(int *a, int i, int n) {
  if (i == n)
    return 0;
  else {
    return a[i] + sumofarr(a, i + 1, n);
  }
}

int main() {
  printf("Enter number of elements in array : ");
  int n;
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements : \n");
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    arr[i] = c;
  }
  printf("sum of arr : %d", sumofarr(arr, 0, 5));
}
