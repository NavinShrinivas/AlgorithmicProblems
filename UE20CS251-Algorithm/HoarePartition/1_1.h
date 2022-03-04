#ifndef HOARE_H
#define HOARE_H
#include <stdio.h>
#include <stdlib.h>
void quick_sort(int a[], int l, int r);
// a is start of arry, b is end
int partition(int a[], int l, int r);
void disp(int *a, int n);
#endif
