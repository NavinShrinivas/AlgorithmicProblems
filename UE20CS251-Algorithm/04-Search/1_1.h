#ifndef COUNT_H
#define COUNT_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void populate(int a[],int n);
int search(int a[],int n,int key);
int search_with_count(int a[],int n,int key,int* count);
int recursive_search_with_count(int a[],int n,int key,int* count);
#endif
