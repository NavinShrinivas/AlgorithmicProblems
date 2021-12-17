// big plans for trie tree , i wanna do "browser search result" where
// the search results are in no proiortiy, littul simpler
// implmentation Ill also demo how power trie trees are by handliong 10000
// entries

#include "1_1.h"
#include <stdio.h>

int main() {
  struct node *root = (struct node *)malloc(sizeof(struct node));
  for (int i = 0; i < 27; i++) {
    root->connect[i] = NULL;
  }
  root->end = false;
  bool file_flag = true; // purely for the 10000 input demo
  /*
   *printf("File operations [Y/n]: ");
   *char op;
   *scanf("%c", &op);
   *if ((int)op == 89) // string operations can go to hell
   *  file_flag = true;
   *else
   *  file_flag = false;
   */
  // im ditching this file operatins part,but the search engine searching
  // work!!!!!!!
  if (file_flag) {
    printf(
        "NOTE : THIS TRIE IMPL CAN NOT HANDLE CAPITAL LETTERS , also one can "
        "modify the code to do it,not hard \n");
    while (true) {
      printf("1.Enter a string \n");
      printf("2.Remove a string \n");
      printf("3.Search for a string [constant time] \n");
      printf("4.Search engine type results \n");
      printf("Enter choice : ");
      int choice;
      scanf("%d", &choice);
      if (choice == 1) {
        char str[10000]; // assumption that string wont be longer than 10000
        printf("Enter string : ");
        scanf("\t%[^\n]%*c", str);
        /*printf("%s", str); // testing*/
        TrieTreeInsertIterative(root, str);
      } else if (choice == 3) {
        char str[10000]; // assumption that string wont be longer than 10000
        printf("Enter string : ");
        scanf("\t%[^\n]%*c", str);
        TrieTreeExactMatch(root, str);
      } else if (choice == 4) {
        char str[10000]; // assumption that string wont be longer than 10000
        printf("Enter string : ");
        scanf("\t%[^\n]%*c", str);
        TrieTreeSearchEngine(root, str);
      }
    }
  }
}
