#include "1_1.h"

void TrieTreeInsertIterative(struct node *root, char *str) {
  int i = 0;
  struct node *curr = root;
  while (str[i] != '\0') {
    if (str[i] == ' ') {
      // i am handling space as well

      if (curr->connect[26] != NULL) { // word cobo with space exists
        curr = curr->connect[26];
      } else { // time for new node
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        for (int j = 0; j < 27; j++) {
          temp->connect[i] = NULL;
        }
        temp->end = false;
        curr->connect[26] = temp;
        curr = temp;
      }
    }
    // first check if the word combo already exists:
    else if (curr->connect[(int)str[i] - 96 - 1] != NULL)
      curr = curr->connect[(int)str[i] - 96 - 1];
    else {
      // lets get one new node ready
      struct node *temp = (struct node *)malloc(sizeof(struct node));
      for (int j = 0; j < 27; j++) {
        temp->connect[i] = NULL;
      }
      temp->end = false;
      curr->connect[(int)str[i] - 96 - 1] = temp;
      curr = temp;
    }
    i++;
  }
  // now curr will obv be the last node for this strings
  // thus lets set the end flag;
  curr->end = true;
  printf("\n String entered to tree! \n \n");
  return;
}

void TrieTreeExactMatch(struct node *root, char *str) {
  struct node *curr = root;
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == ' ') {
      if (curr->connect[26] != NULL)
        curr = curr->connect[26];
      else {
        printf("\n String Exact match not found :( \n \n");
        return;
      }
    } else {
      if (curr->connect[(int)str[i] - 96 - 1] == NULL) {
        printf("\n String with exact match not found :( \n \n ");
        return;
      } else {
        curr = curr->connect[(int)str[i] - 96 - 1];
      }
    }
    i++;
  }
  // if it has reached here meaning it has found a string with exact string
  // pattern, only check left is to see if the string ends here which is
  // specific to ExactMatch function
  if (curr->end == true)
    printf("\n Found a string with exact match! \n \n");
  else
    printf("\n String with exact match not found :( \n \n");

  return;
}
