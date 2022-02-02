#ifndef STRING_H
#define STRING_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*
 *- string length
 *- string compare
 *- string copy
 */
void mystrcpy(char *dst, char *src);
int mystrlen(char *str);
int mystrcmp(char *str1, char *str2);
#endif
