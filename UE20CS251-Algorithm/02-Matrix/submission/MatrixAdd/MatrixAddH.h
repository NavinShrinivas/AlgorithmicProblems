#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations :
double time_elapsed(struct timespec start, struct timespec end);
void gen_matrix(int n, int a[][n]);
void print_matrix(int n, int a[][n]);
void print_sum(int n, int a[][n], int b[][n]);
