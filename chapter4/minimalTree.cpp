#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

treeNode* minimalHelper(vector<int>& nums, int start, int end){
  if(start > end) return NULL;
  int mid = (start + end)/2;
  treeNode* root = new treeNode(nums[mid]);
  root->left = minimalHelper(nums, start, mid-1);
  root->right = minimalHelper(nums, mid+1, end);
  return root;
}

treeNode* minimalTree(vector<int>& nums){
  return minimalHelper(nums, 0, nums.size()-1);
}
void inOrder(treeNode* root){
  if(root != NULL){
    inOrder(root->left);
    cout<<root->val;
    inOrder(root->right);
  }
}
int main(){
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  treeNode* root = minimalTree(nums);
  inOrder(root);
  return 0;
}
