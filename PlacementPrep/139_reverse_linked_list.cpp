#include<bits/stdc++.h>

struct Node{
  int data;
  struct Node* next;
};


class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        struct Node* current = head;
        struct Node* previous = NULL;
        struct Node* next = NULL;

        while(current!=NULL){
          next = current->next;
          current->next = previous;

          previous=current;
          current = next;
        }
        head = previous;
        return head;
    }
    
};
