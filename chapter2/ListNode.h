#include <iostream>
using namespace std;
struct ListNode{
  int val;
  ListNode* next;
ListNode(int _val):val(_val), next(nullptr){}
};

void push_front(ListNode* &head, int val){
  ListNode* node = new ListNode(val);
  node->next = head;
  head = node;
}

void printList(ListNode* head){
  ListNode* curr = head;
  while(curr != nullptr){
    cout<<curr->val<<"->";
    curr = curr->next;
  }
  cout<<endl;
}
