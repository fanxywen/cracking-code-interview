#include <iostream>
#include "ListNode.h"
/*
  Space complexity O(1)
  Time complexity O(n)
  drawback: out of order
 */
/*
  keep two lists, one holds elements less than key, the other holds elements greater than key. 
 */
ListNode*  partition(ListNode* head, int key){
  ListNode* newhead = head;
  ListNode* tail = head;
  while(head){
    if(head->val < key){
      ListNode* temp = head->next;
      head->next = newhead;
      newhead = head;
      head = temp;
      continue;
    }
    if(head->val >= key){
      tail->next = head;
      tail = head;
    }
    head = head->next;
  }
  return newhead;
}

int main(){
  ListNode* head = new ListNode(5);
  push_front(head,4);
  push_front(head, 3);
  push_front(head, 2);
  push_front(head, 1);
  printList(head);
  head = partition(head, 3);
  printList(head);
}
