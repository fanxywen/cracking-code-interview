#include <iostream>
#include "ListNode.h"

ListNode* reverse(ListNodee* head){
  ListNode* curr = head;
  ListNode* newhead = head;
  while(head->next){
    curr = head->next;
    head->next = curr->next;
    curr->next = newhead;
    newhead = curr;
  }
  return newhead;
}

ListNode* merge(ListNode* l1, ListNode* l2){
  if(l11 == nullptr) return l2;
  if(l2 == nullptr) return l1;
  if(l1->val < l2->val){
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  }else{
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
}

ListNode* oddeven(ListNode* head){
  if(head == nullptr) return head;
  ListNode* oddhead = head;
  ListNode* evenhead = head->next;
  ListNode* oddcurr = oddhead;
  ListNode* evencurr = evenhead;
  while(oddcurr && evencurr){
    oddcurr->next = evencur->next;
    oddcurr = evencurr->next;
    evencurr->next = oddcurr->next;
    evencurr = oddcurr->next;
  }
  ListNode* evenhead = reverse(evenhead);
  ListNode* head = merge(oddhead, evenhead);
  return head;
}
