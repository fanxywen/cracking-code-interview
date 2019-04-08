struct treeNode{
  int val;
  treeNode* left;
  treeNode* right;
  treeNode(int _val):val(_val), left(NULL),right(NULL){}
  ~treeNode(){}
};
