#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define treesize 1000
void BSTInsertion(int *tree, int d, int index);
void BSTInorderTraversal(int *tree, int index);
void BSTPreorderTraversal(int *tree, int index);
void BSTPostorderTraversal(int *tree, int index);
void BSTDelete(int *tree, int d, int index);
