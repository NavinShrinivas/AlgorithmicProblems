#ifndef CALLBACK_H
#define CALLBACK_H
#include <stdio.h>
int mul(int x, int y);
int add(int x, int y);
int callback(int x, int y, int (*fn_ptr)(int, int));
int arr_collect(int *a, int n, int init, int (*fn)(int, int));
int mul(int x, int y);
int add(int a, int b);
int odd(int x);
int is_any(int *a, int n, int (*fn)(int));
int is_all(int *a, int n, int (*fn)(int));
#endif
