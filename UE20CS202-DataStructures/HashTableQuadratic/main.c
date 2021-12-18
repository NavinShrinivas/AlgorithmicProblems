// Dont bother learning this as a seperate program
// its very similar to the hash table linear program
// line 22 in 1_1.c is the main diff
// similar changes to all fns
#include "1_1.h"

int main() {
  struct person *table[tablesize] = {NULL}; // NULL reps EMPTY
  while (true) {
    printf("1.Inset to Hash Table \n");
    printf("2.Search in Hash Table \n");
    printf("3.Delete from Hash Table \n");
    printf("4.Display entire Hash Table \n");
    int choice;
    printf("Enter Choice : ");
    scanf("%d", &choice);
    if (choice == 1) {
      struct person *d = (struct person *)malloc(sizeof(struct person));
      printf("Enter phone number : ");
      scanf("%lli", &(d->phone));
      printf("Enter name : ");
      scanf("\t%[^\n]%*c", d->name);
      HashTableInsert(table, d);
    } else if (choice == 2) {
      printf("Enter phone number to search : ");
      ll ph;
      scanf("%lli", &ph);
      HashTableSearch(table, ph);
    } else if (choice == 3) {
      printf("Enter phone number to delete : ");
      ll ph;
      scanf("%lli", &ph);
      HashTableDelete(table, ph);
    } else if (choice == 4) {
      HashTableDisplay(table);
    } else {
      break;
    }
  }
}
