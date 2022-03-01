#ifndef SORT_H
#define SORT_H
#include <stdbool.h>
#include <stdio.h>
void insert_edge(
    int a[][1000], int key1,
    int key2); // everything in row major hence, number of cols is needed
void source_removal(int a[][1000], int size);

#endif
