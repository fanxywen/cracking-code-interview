#include <iostream>
#include <string>
using namespace std;
void url(char* str, int length){
  int num = 0;
  for(int i = 0; i < length; ++i){
    if(str[i] == ' '){
      ++num;
    }
  }
  int total = length + 2 * num;
  int j = total - 1;
  //modify from the end of the string
  for(int i = length - 1; i >= 0; --i){
    if(str[i] != ' '){
      str[j] = str[i];
      j--;
    }else{
      str[j--] = '0';
      str[j--] = '2';
      str[j--] = '%';
    }
  }
  //  return str;
}

int main(){
  char str[] = "Mr John Smith    ";
  cout<<"input: "<<str<<endl;
  url(str, 13);
  cout<<"output: "<<str<<endl;
  return 0;
}
