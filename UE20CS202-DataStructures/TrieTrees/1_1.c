#include "1_1.h"
#include <stdio.h>
#include <string.h>

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
          temp->connect[j] = NULL; // god this too so long to debug :,( , i
                                   // subscripted with i not j,god im an idito
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
        temp->connect[j] = NULL;
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

void TTSEHelper(struct node *curr, char *tempstr) {
  if (curr->end == true) {
    printf("\n %s \n", tempstr);
    // the end of one can be middle for other string hence continue search
    for (int i = 0; i < 27; i++) {
      if (i == 26) {
        if (curr->connect[i] != NULL) {
          char t[1000];
          strcpy(t, tempstr);
          strcat(t, " ");
          TTSEHelper(curr->connect[26], t);
        } else {
          continue; // important, this is so we dont generate random mess
          // at this point i figured that the way im hanndling spaces is very
          // bad xD too late to changes stuff now
        }
      } else if (curr->connect[i] != NULL) {
        char t[1000];
        strcpy(t, tempstr);
        char tt[2];
        tt[0] = i + 96 + 1;
        tt[1] = '\0';  // welcome to the world od C where string witout
                       // terminating chars break your pgrams
        strcat(t, tt); // i feel this crap string library is causing me
                       // progblems, it wasnt
        TTSEHelper(curr->connect[i], t);
      }
    }
    return;
  }
  for (int i = 0; i < 27; i++) {
    if (i == 26) {
      if (curr->connect[i] != NULL) {
        char t[1000];
        strcpy(t, tempstr);
        strcat(t, " ");
        TTSEHelper(curr->connect[26], t);
      } else {
        continue; // important, this is so we dont generate random mess
        // at this point i figured that the way im hanndling spaces is very bad
        // xD too late to changes stuff now
      }
    } else if (curr->connect[i] != NULL) {
      char t[1000];
      strcpy(t, tempstr);
      char tt[2];
      tt[0] = i + 96 + 1;
      tt[1] = '\0'; // welcome to the world od C where string witout terminating
                    // chars break your pgrams
      strcat(t, tt); // i feel this crap string library is causing me progblems,
                     // it wasnt
      TTSEHelper(curr->connect[i], t);
    }
  }
  return;
}

void TrieTreeSearchEngine(struct node *root, char *str) {
  // lets first proceed the node to given string nad as much as available
  // did not undestadn the previoud comment? lemme explain :
  // in database : my name is a and b
  // search query : my name is b
  // our node should have proceeded till : my name is
  //
  struct node *curr = root;
  int i = 0;
  char tempstr[1000];
  while (str[i] != '\0') {
    if (str[i] == ' ') {
      if (curr->connect[26] != NULL) {
        curr = curr->connect[26];
        tempstr[i] = str[i];
      } else {
        break;
      }
    } else {
      if (curr->connect[(int)str[i] - 96 - 1] == NULL) {
        break;
      } else {
        tempstr[i] = str[i];
        curr = curr->connect[(int)str[i] - 96 - 1];
      }
    }
    i++;
  }
  TTSEHelper(curr, tempstr);
}
