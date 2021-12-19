#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define tablesize 1000
typedef long long int ll;

// to store the data into array
struct person {
  ll phone;
  char name[30];
  struct person* link; //for seperate chaining
};
//we will also have to use an array of type struct person* for seperate chaining



void HashTableInsert(struct person **table, struct person *d);
void HashTableSearch(struct person **table, ll ph); 
void HashTableDelete(struct person **table, ll ph); 
void HashTableDisplay(struct person **table); 
