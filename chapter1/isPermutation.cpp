#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isPermutation(string& str, string& tar){
  map<char, int> hash;
  if(str.size() != tar.size()) return false;
  for(int i = 0; i < str.size(); i++){
    if(hash.find(str[i]) == hash.end()){
      hash[str[i]] = 1;
    }else{
      hash.erase(hash.find(str[i]));
    }
    if(hash.find(tar[i]) == hash.end()){
      hash[tar[i]] = 1;
    }else{
      hash.erase(hash.find(tar[i]));
    }
  }
  if(hash.empty()) return true;
  return false;
}

int main(){
  string str;
  string tar;
  cout<<"Input two strings"<<endl;
  getline(cin, str);
  getline(cin, tar);
  bool res = isPermutation(str, tar);
  cout<<"Result: "<<res<<endl;
  return 0;
}
