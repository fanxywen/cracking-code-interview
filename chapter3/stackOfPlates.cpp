#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class stackPlate{
private:
  vector<stack<int> > plates;
  int capacity;
public:
  stackPlate(int _cap): plates(), capacity(_cap){}
  ~stackPlate(){}
  bool isFull(){
    int sz = plates.size();
    return plates[sz-1].size() == capacity;
  }
  bool isEmpty(){
    return plates.empty();
  }
  void push(int value){
    if(isEmpty() || isFull()){
      stack<int> newStack;
      newStack.push(value);
      plates.push_back(newStack);
    }else{
      int sz = plates.size();
      plates[sz-1].push(value);
    }
  }
  int pop(){
    if(plates.empty()){
      cerr<<"empty stack"<<endl;
      return -1;
    }
    int sz = plates.size();
    while(plates[plates.size()-1].empty()){
      plates.pop_back();
    }
    sz = plates.size();
    int value = plates[sz-1].top();
    plates[sz-1].pop();
    return value;
  }
  int popAt(int index){
    int sz = plates.size();
    if(index >= sz){
      cerr<<"index out of range"<<endl;
      return -1;
    }
    if(plates[index].empty()){
      cerr<<"target stack empty"<<endl;
      return -1;
    }
    int value = plates[index].top();
    plates[index].pop();
    return value;
  }
};

int main(){
  stackPlate mystack(3);
  mystack.push(1);
  mystack.push(2);
  mystack.push(3);
  mystack.push(4);
  mystack.push(5);
  int value = mystack.pop();
  cout<<"pop out "<<value<<endl;
  value = mystack.popAt(0);
  cout<<"pop out "<<value<<endl;
  value = mystack.pop();
  cout<<"pop out "<<value<<endl;
  return 0;
}
