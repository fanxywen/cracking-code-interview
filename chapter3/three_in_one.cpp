#include <iostream>
#include <vector>
using namespace std;

/*
  fixed division
 */
class mystack{
private:
  int capacity;
  vector<int>* stackArray;
  vector<int>* stackSize;
  int numStack = 3;
public:
  mystack(int cap):capacity(cap), stackArray(), stackSize(){
    stackArray = new vector<int>(numStack * cap);
    stackSize = new vector<int>(numStack);
  }
  ~mystack(){}
  bool isFull(int num){
    return (*stackSize)[num] == capacity;
  }
  bool isEmpty(int num){
    return (*stackSize)[num] == 0;
  }
  int topIndex(int num){
    int offset = num * capacity;
    int size = (*stackSize)[num];
    return offset+size-1;
  }
  void push(int num, int value){
    if(isFull(num)){
      cerr<<"usage: Stack is full"<<endl;
      return;
    }else{
      (*stackSize)[num]++;
      (*stackArray)[topIndex(num)] = value;
    }
  }
  void pop(int num){
    if(isEmpty(num)){
      cerr<<"stack is empty"<<endl;
      return;
    }else{
      (*stackArray)[topIndex(num)] = 0;
      (*stackSize)[num]--;
    }
  }
  int peek(int stackNum){
    if(isEmpty(stackNum)){
      cerr<<"stack empty"<<endl;
      return -1;
    }else{
      int index = topIndex(stackNum);
      return (*stackArray)[index];
    }
  }
};


int main(){
  mystack stack(3);
  stack.push(0, 5);
  stack.push(2, 10);
  stack.push(1, 4);
  stack.push(0, 6);
  int top = stack.peek(0);
  cout<<"stack 0 top "<<top<<endl;
  stack.pop(0);
  top = stack.peek(0);
  cout<<"now stack 0 top "<<top<<endl;
  top = stack.peek(1);
  cout<<"stack 1 top "<<top<<endl;
  top = stack.peek(2);
  cout<<"stack 2 top "<<top<<endl;
  return 0;
}
