// Hast table impl using
// open hashing also called seperate chainin

#include "1_1.h"

int main() {
  struct person *table[tablesize] = {NULL};
  while (true) {
    printf("1.Inset to Hash Table \n");
    printf("2.Search in Hash Table [search by phone]\n");
    printf("3.Delete from Hash Table \n");
    printf("4.Disaply full HashTable \n");
    int choice;
    printf("Enter Choice : ");
    scanf("%d", &choice);
    if (choice == 1) {
      struct person *d = (struct person *)malloc(sizeof(struct person));
      printf("Enter phone number : ");
      scanf("%lli", &(d->phone));
      printf("Enter name : ");
      scanf("\t%[^\n]%*c", d->name);
      d->link = NULL; // this wont happen in linear probing
      HashTableInsert(table, d);
    } else if (choice == 2) {
      ll ph;
      printf("Enter phone number : ");
      scanf("%lli", &ph);
      HashTableSearch(table, ph);
    } else if (choice == 3) {
      ll ph;
      printf("Enter phone number : ");
      scanf("%lli", &ph);
      HashTableDelete(table, ph);
    } else if (choice == 4) {
      HashTableDisplay(table);
    }
  }
  return 0;
}
