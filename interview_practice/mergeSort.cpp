#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& num, int start, int mid, int end){
  vector<int> temp(end - start + 1);
  int i = start;
  int j = mid+1;
  int k = 0;
  while(i <= mid && j <= end){
    if(num[i] < num[j]){
      temp[k] = num[i];
      i++;
    }else{
      temp[k] = num[j];
      j++;
    }
    k++;
  }
  while(i <= mid){
    temp[k] = num[i];
    k++;
    i++;
  }
  while(j <= end){
    temp[k] = num[j];
    k++;
    j++;
  }
  for(int i = 0; i < temp.size(); i++){
    num[i+start] = temp[i];
  }
}

void mergeSort(vector<int>& num, int start, int end){
  if(start < end){
    int mid = (end + start) / 2;
    mergeSort(num, start, mid);
    mergeSort(num, mid+1, end);
    merge(num, start, mid, end);
  }
}

int main(){
  vector<int> arr = {5, 4 ,3, 1, 2, 7};
  mergeSort(arr, 0, 5);
for(int i = 0; i < arr.size(); i++){
cout<<arr[i]<<" ";
}
return 0;
}
