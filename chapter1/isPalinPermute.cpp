#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <ctype.h>
using namespace std;

int isPalinPermute(string& str){
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  cout<<str<<endl;
  map<char, int> hash;
  int start = 0;
  int end = str.size()-1;
  while(start <= end){
    if(hash.find(str[start]) == hash.end()){
      hash[str[start]] = 1;
    }else{
      hash.erase(hash.find(str[start]));
    }
    if(hash.find(str[end]) == hash.end()){
      hash[str[end]] = 1;
    }else{
      hash.erase(hash.find(str[end]));
    }
    start++;
    end--;
  }
  if(hash.empty() || hash.size() == 1) return true;
  return false;
}

int main(){
  string str = "Tact Coa";
  bool res = isPalinPermute(str);
niif(res == true){
  cout<<"Result: "<<res<<endl;
  }
  return 0;
}
