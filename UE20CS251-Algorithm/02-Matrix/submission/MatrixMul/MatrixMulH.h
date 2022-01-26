#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int n, int a[][n]);
void mul_matrix(int n, int a[][n], int b[][n], int c[][n]);
double time_elapsed(struct timespec start, struct timespec end);
void gen_matrix(int n, int (*a)[n]);
