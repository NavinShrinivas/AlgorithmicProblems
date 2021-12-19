#include "1_1.h"
#include <stdio.h>

void BSTInsertion(int *tree, int d, int index) {

  // in this function the index parameter may seem wierd having
  // fixed inital value of 1 , but this was done inorder to get
  // recursive function , imo much neater!
  if (tree[index] == 0) {
    tree[index] = d;
    printf("\n Inserted %d to tree! \n \n", d);
    return;
  } else if (d >= tree[index]) {
    BSTInsertion(tree, d, index * 2); // index*2 is looking intp right subtree
  } else {
    BSTInsertion(tree, d, (index * 2) + 1);
  }
}

// Inorder : LNR
// Postorder : LRN
// Preorder : NLR

void BSTInorderTraversal(int *tree, int index) {
  // reason for index same as last function
  if (tree[index] == 0)
    return;

  BSTInorderTraversal(tree, (index * 2) + 1);
  printf("%d-> ", tree[index]);
  BSTInorderTraversal(tree, (index * 2));
}

void BSTPreorderTraversal(int *tree, int index) {
  // reason for index same as last function
  if (tree[index] == 0)
    return;

  printf("%d-> ", tree[index]);
  BSTInorderTraversal(tree, (index * 2) + 1);
  BSTInorderTraversal(tree, (index * 2));
}

void BSTPostorderTraversal(int *tree, int index) {
  // reason for index same as last function
  if (tree[index] == 0)
    return;

  BSTInorderTraversal(tree, (index * 2) + 1);
  BSTInorderTraversal(tree, (index * 2));
  printf("%d-> ", tree[index]);
}

// inorder succesor is leftmost node in the right subtee and is needed for soma
// case of deleting
int InorderScuccesor(int *tree, int index) {
  int right = index * 2;
  for (int i = right; i < treesize; i = ((i * 2) + 1)) {
    if (tree[i] == 0)
      return i / 2;
  }
}
// this righrfully is not the entire impl for inorder succesor
// see the picture in this folder to handle other cases as well

void BSTDelete(int *tree, int d, int index) {
  if (tree[index] == 0) {
    printf("\n Element not found :( \n \n");
    return;
  } else if (tree[index] > d)
    BSTDelete(tree, d, (index * 2) + 1);
  else if (tree[index] < d)
    BSTDelete(tree, d, index * 2);

  else {
    int right = index * 2, left = (index * 2) + 1;
    if (tree[right] == 0 && tree[left] == 0) {
      tree[index] = 0; // deleting the node
      printf("\n Element deleted! \n \n");
      return;
    } else if (tree[right] != 0 && tree[left] == 0) {
      tree[index] = tree[right];
      tree[right] = 0;
      printf("\n Element deleted! \n \n");
      return;
    } else if (tree[left] != 0 && tree[right] == 0) {
      tree[index] = tree[left];
      tree[left] = 0;
      printf("\n Element deleted! \n \n");
      return;
    }
    // this is the case if the node has both childer non empty
    int inorders = InorderScuccesor(tree, index);
    tree[index] = tree[inorders];
    tree[inorders] = 0;
    printf("\n Element deleted! \n \n");
    return;
  }
}
