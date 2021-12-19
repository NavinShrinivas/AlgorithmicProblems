#include "1.h"

void pushe(struct head *head, int d) {
  if (head->top == -1) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->link = NULL;
    head->link = temp;
    (head->top)++;
    return;
  } else {
    struct node *curr = head->link;
    while (curr->link != NULL)
      curr = curr->link;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->link = NULL;
    curr->link = temp;
    (head->top)++;
    printf("Element with value %d is pushed on to stack \n", temp->data);
    return;
  }
}

void pope(struct head *head) {
  if (head->top == -1)
    printf("Stack underflow , nothing to pop\n");
  else if (head->top == 0) {
    printf("Element with value %d is poped\n", head->link->data);
    head->link = NULL;
    (head->top)--;
    return;
  } else {
    struct node *curr = head->link;
    struct node *del = curr->link;
    while (del->link != NULL) {
      curr = del;
      del = del->link;
    }
    curr->link = NULL;
    (head->top)--;
    printf("Element with value %d is popped\n", del->data);
    return;
  }
}

void displaystack(struct head *head) {
  if (head->top == -1) {
    printf("Stack is empty\n");
    return;
  }
  printf("Start of stack ->");
  struct node *curr = head->link;
  while (curr->link != NULL) {
    printf("%d ->", curr->data);
    curr = curr->link;
  }
  printf("%d ->", curr->data);
  printf("End of stack\n");
}
