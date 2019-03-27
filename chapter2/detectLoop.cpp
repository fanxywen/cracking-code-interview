#include <iostream>
#include "ListNode.h"
#include <map>
using namespace std;

bool detectLoop(ListNode* head){
  map<ListNode*, int> hash;
  ListNode* curr = head;
  while(head){
    if(hash.find(head) == hash.end()){
      hash[head] = 1;
    }else{
      return true;
    }
    head = head->next;
  }
  return false;
}

int main(){
  ListNode* head = new ListNode(5);
  ListNode* tail = head;
  push_front(head, 4);
  push_front(head, 3);
  ListNode* cycle = head;
  tail->next = cycle;
  push_front(head, 2);
  push_front(head, 1);
  bool res = detectLoop(head);
  cout<<"Result: "<<res<<endl;
  return 0;
}
