#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void rotate(vector<vector<int> >& matrix){
  int n = matrix.size();
  int start = 0;
  int end = n - 1;
  while(start < end){
    swap(matrix[start], matrix[end]);
    start++;
    end--;
  }

  for(int i = 0; i < n; ++i){
    for(int j = i+1; j < n; ++j){
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }    
  }
}

int main(){
  vector<vector<int> > matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  rotate(matrix);
  for(int i = 0; i < matrix.size(); i++){
    for(int j = 0; j < matrix.size(); ++j){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
