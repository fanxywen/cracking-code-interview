#include <iostream>
#include "ListNode.h"
#include <map>
using namespace std;
/*
  space complexity: O(N)
  time complexity: O(N)
 */
bool detectLoop(ListNode* head){
  map<ListNode*, int> hash;
  if(head == nullptr || head->next == nullptr) return false;
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
/*
  space complexity: O(1)
  time complexity: O(N)
 */
ListNode* detectLoopII(ListNode* head){
  if(head == nullptr || head->next == nullptr) return nullptr;
  ListNode* slow = head;
  ListNode* fast = head->next;
  ListNode* entry = head;
  while(slow != fast){
    slow = slow->next;
    if(!fast || !fast->next || !fast->next->next) return nullptr;
    fast = fast->next->next;
  }
  while(slow != entry){
    entry = entry->next;
    if(!slow->next || !slow->next->next) return nullptr;
    slow = slow->next->next;
  }
  return slow;
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
  ListNode* res = detectLoopII(head);
  cout<<"Result: "<<res->val<<endl;
  return 0;
}
