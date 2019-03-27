#include <iostream>
#include "ListNode.h"
using namespace std;
/*
 brute force: O(n^2)
 two pointers: O(n) maintain constant gap between two pointers
 *adding dummy node  
 */

ListNode* kth(ListNode* head, int k){
  if(head == nullptr) return head;
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  ListNode* first = dummy;
  ListNode* second = dummy;
  for(int i = 0; i < k; i++){
    second = second->next;
  }
  while(second != nullptr){
    first = first->next;
    second = second->next;
  }
  delete dummy;
  return first;
}

int main(){
  ListNode* head = new ListNode(1);
  push_front(head, 2);
  push_front(head, 3);
  push_front(head, 4);
  push_front(head, 5);
  printList(head);
  ListNode* res = kth(head, 3);
  printList(res);
  delete head;
  return 0;
}



