#include <iostream>
#include <algorithm>
#include "tree.h"

using namespace std;

int computeHeight(treeNode* root){
  if(root == NULL) return 1;
  return max(computeHeight(root->left)+1, computeHeight(root->right)+1);
}

bool isBalance(treeNode* root){
  if(root == NULL) return true;
  
}
