#include "1_1.h"

int BalanceFactor(struct node *root) {
  // left - right subtrees will give us Balance Factor , buuuuuut NULL :,(
  int lh, rh;
  if (root->left == 0)
    lh = 0;
  else
    lh = root->left->height;

  if (root->right == 0)
    rh = 0;
  else
    rh = root->right->height;

  return lh - rh;
}

struct node *RightRotate(struct node *root) {
  struct node *temp = root->left;
  root->left = temp;
  temp->right = root;
}

void AVLInsert(struct node *root, int d) {
  if (root == NULL) {
    root = (struct node *)malloc(sizeof(struct node));
    root->data = d;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;
  } else if (d < root->data) {
    if (root->left == NULL) {
      struct node *temp = (struct node *)malloc(sizeof(struct node));
      temp->right = NULL;
      temp->left = NULL;
      temp->data = d;
      temp->height = 1;
      root->left = temp;
    } else {
      AVLInsert(root->left, d);
    }
  } else {
    if (root->right == NULL) {
      struct node *temp = (struct node *)malloc(sizeof(struct node));
      temp->right = NULL;
      temp->left = NULL;
      temp->data = d;
      temp->height = 1;
      root->right = temp;
    } else {
      AVLInsert(root->right, d);
    }
  }
  // update height of all parent nodes all the way to root node.
  root->height = root->height + 1;
  // balance if BF is -2 or 2
  if (BalanceFactor(root) == 2) {
    // meaning left subtree is bigger than right subtree
    // now need to check if left move is needed
    if (d > root->left->data) {
      root = LeftRightRotate(root);
    } else {
      RightRotate(root);
    }
  }
}
