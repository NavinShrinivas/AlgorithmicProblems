#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>


//doing for string, meaning a string can have connection to 26[max] nodes
//one indicator for end of string char as well



//as a guide here ive dropped the ascii values for letters we are gonna be
//dealing with : 
//a-z : 97-122
//thus, if connect[int(char)-97] is present we know that a word with similar
//char sequences has existed so far


//Unlike slides i also wanna handle spaces in strings, literally a browser search
//engine, thus node 27 [index 26]for spaces.
//now now let's not get too ahead of ourself , we will not have nay sort of logic in the search
//unlike google, who in their auto complete engine use negative and various other logic
struct node{
    struct node* connect[27];
    bool end;
};
void TrieTreeInsertIterative(struct node *root, char *str); 
void TrieTreeExactMatch(struct node *root, char *str); 
