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
    
  }
}
