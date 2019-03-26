#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> >& power_set(vector<int>& nums, vector<vector<int> >& ans){
  //  vector<vector<int> > ans;
  vector<int> subset(1, nums[0]);
  ans.push_back(subset);
  //  subset.push_back(nums[0]);
  // ans.push_back(subset);
  for(int i = 1; i < nums.size(); i++){
    int n = ans.size();
    for(int j = 0; j < n; j++){
      vector<int> temp = ans[j];
      temp.push_back(nums[i]);
      ans.push_back(temp);
    }
    vector<int> self(1, nums[i]);
    ans.push_back(self);
  }
  return ans;
}

int main(){
  vector<int> nums(3,1);
  nums[1] = 2;
  nums[2] = 3;
  vector<vector<int> > ans;
  vector<vector<int> > subsets = power_set(nums, ans);
for(int i = 0; i < subsets.size(); ++i){
  for(int j = 0; j < subsets[i].size(); ++j){
    std::cout<<subsets[i][j]<<" ";
  }
  std::cout<<std::endl;
 }
return 0;
}
