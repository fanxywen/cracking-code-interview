#include <iostream>
#include <stack>
using namespace std;

class MinStack{
private:
  stack<int> mystack;
  stack<int> minstack;
public:
  void push(int value){
    mystack.push(valu);
    if(minstack.empty() || value <= getMin()){
      minstack.push(value);
    }
  }
  void pop(){
    if(mystack.top() == getMin()) minstack.pop();
    mystack.pop();
  }
  int top(){
    return mystack.top();
  }
  int getMin(){
    return minstack.top();
  }
};
