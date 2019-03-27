#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
  brute force: O(n^2)
  hash: O(n)
*/

int isUnique(string str){
map<char, int> hash;
for(int i = 0; i < str.size(); i++){
if(hash.find(str[i]) != hash.end()){
return -1;
}else{
hash[str[i]] = 1;
}
}
return 0;
}

int main(){
string str;
cin>>str;
int res = isUnique(str);
cout<<"res "<<res<<endl;
return 0;
}
