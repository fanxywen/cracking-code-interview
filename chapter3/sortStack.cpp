#include <iostream>
#include <stack>
using namespace std;

class sortStack{
private:
  stack<int> mainStack;
  stack<int> helper;
public:
  sortStack(){}
  ~sortStack(){}
  void push(int value){
    if(mainStack.empty()){
      mainStack.push(value);
      return;
    }
    int min = mainStack.top();
    if(value <= min){
      mainStack.push(value);
    }else{
      while(!mainStack.empty() && value > mainStack.top()){
	helper.push(mainStack.top());
	mainStack.pop();
      }
      mainStack.push(value);
      while(!helper.empty()){
	mainStack.push(helper.top());
	helper.pop();
      }
    }
  }
  int pop(){
    int min = mainStack.top();
    mainStack.pop();
    return min;
  }
  bool empty(){
    return mainStack.empty();
  }
};

int main(){
  sortStack stk;
  stk.push(5);
  stk.push(3);
  stk.push(4);
  stk.push(6);
  while(!stk.empty()){
    cout<<stk.pop()<<endl;
  }
  return 0;
}
