#include "1_1.h"

int HashFunction(ll key) {
  int fn = key % 10;
  key /= 10;
  fn += key % 10;
  int index = (fn * 2) % 7; // there comes the prime number for a good hash fn
  // sadly no good hash fn can avoid collision of 2 identical keys
  return index;
}

void HashTableInsert(struct person **table, struct person *d) {
  ll ph = d->phone;
  int index = HashFunction(ph);
  if (table[index] == NULL) {
    table[index] = d;
    printf("\n Details inserted to HashTable :) \n \n");
    return;
  } else {
    // meaning something is already taking up this space
    // best way to test this fn out is by enterin 2 records with same number
    struct person *prev = table[index];
    struct person *curr = prev->link;
    // im using two pointer to do this chaining, this is for extra memory safety
    // i dont want stupid cases crashing my code
    while (curr != NULL) {
      prev = curr;
      curr = prev->link;
    }
    prev->link = d;
    printf("\n Details inserted to HashTable [chaining was done!] :) \n \n");
  }
}

void HashTableSearch(struct person **table, ll ph) {
  int index = HashFunction(ph);
  if (table[index] == NULL) {
    printf("\n Nope.No record with that phone number was found :(");
  } else {
    bool hit_flag = false; // its possible out program was confused,how?
    // some other other number has taken this pos with has same hash value as
    // current search number , thus this check
    printf("\n Record found with this number : \n");
    struct person *curr = table[index];
    while (curr != NULL) {
      if (curr->phone == ph) {
        hit_flag = true;
        printf("\n\tPhone number : %llu", curr->phone);
        printf("\n\tName : %s\n", curr->name);
        curr = curr->link;
      } else // while coding this , this else definetly bamboolzed me xD
        curr = curr->link;
    }

    if (hit_flag == false) {
      printf("\n Phew that was a close one,I was alsmost bamboozled.");
      printf("\n Nope.No record with that number was found");
    }
  }

  printf("\n End of search! \n \n");
  return;
}

void HashTableDelete(struct person **table, ll ph) {
  int index = HashFunction(ph);
  if (table[index] == NULL) {
    printf(
        "\n No record with such number found.Stop trying to break me :(\n \n");
    return;
  } else if (table[index]->phone == ph) {
    table[index] = table[index]->link;
    printf("\n 1st record with that phone number deleted :) \n \n");
    return;
  } else {
    struct person *prev = table[index];
    struct person *curr = prev->link;
    while (curr != NULL) {
      if (curr->phone == ph) {
        prev->link = curr->link;
        printf(" \n Record with that phone number deleted :) \n \n");
        return;
      } else {
        prev = curr;
        curr = prev->link;
      }
    }
    // if it has reached here mean it could not find any record
    printf("\n No record with such number found :( \n \n");
  }
}

void HashTableDisplay(struct person **table) {
  printf("\n All record found in the Hash Tbale : \n");
  for (int i = 0; i < tablesize; i++) {
    if (table[i] != NULL) {
      struct person *curr = table[i];
      while (curr != NULL) {
        printf("\n\tPhone number : %llu", curr->phone);
        printf("\n\tName : %s\n", curr->name);
        curr = curr->link;
      }

    } else {
      continue;
    }
  }
  printf("\n End of search \n \n");
}
