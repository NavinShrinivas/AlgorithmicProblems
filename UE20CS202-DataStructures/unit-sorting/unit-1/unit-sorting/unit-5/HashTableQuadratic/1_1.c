#include "1_1.h"
#include <stdio.h>

int HashFunction(ll key) {
  int fn = key % 10;
  key /= 10;
  fn += key % 10;
  int index = (fn * 2) % 7;
  return index;
}

void HashTableInsert(struct person **table, struct person *d) {
  ll ph = d->phone;
  int index = HashFunction(ph);
  if (table[index] == NULL) {
    table[index] = d;
    printf("\n Inserted to Hash Table :) \n \n");
    return;
  } else {
    int h = 1;
    while (h < tablesize) {
      index = HashFunction(ph + (h * h));
      if (table[index] == NULL) {
        table[index] = d;
        printf("\n Inserted to Hash Table UwU \n \n");
        return;
      }
      h++;
    }
    printf("\n Table is FULL or right index not found for data :( \n \n");
    return;
  }
}

void HashTableSearch(struct person **table, ll ph) {
  int index = HashFunction(ph);
  if (table[index] != NULL && table[index]->phone == ph) {
    printf("\n Record Found in Hash Table :) : \n ");
    printf("\n  Phone no : %lli ", table[index]->phone);
    printf("\n  Name : %s \n \n", table[index]->name);
    return;
  } else {
    int h = 1;
    while (h < tablesize) {
      index = HashFunction(ph + (h * h));
      if (table[index] != NULL && table[index]->phone == ph) {
        printf("\n Record Found in Hash Table :) : \n \n");
        printf("\n  Phone no : %lli", table[index]->phone);
        printf("\n  Name : %s \n \n", table[index]->name);
        return;
      }
      h++;
    }
    printf("\n Record Not found :( \n \n");
    return;
  }
}

void HashTableDelete(struct person **table, ll ph) {
  int index = HashFunction(ph);
  if (table[index] != NULL && table[index]->phone == ph) {
    table[index] = NULL;
    printf("\n First record with that number deleted! \n \n");
    return;
  } else {
    int h = 1;
    while (h < tablesize) {
      index = HashFunction(ph + (h * h));
      if (table[index] != NULL && table[index]->phone == ph) {
        table[index] = NULL;
        printf("\n Firt record with that number deleted! \n \n");
        return;
      }
      h++;
    }
    printf("\n Record Not found :( \n \n");
    return;
  }
}

void HashTableDisplay(struct person **table) {
  int index = 0;
  printf("\n All records in the table : \n \n");
  while (index < tablesize) {
    if (table[index] != NULL) {
      printf("\n  Phone no : %lli", table[index]->phone);
      printf("\n  Name : %s \n \n", table[index]->name);
    }
    index += 1;
  }
}
