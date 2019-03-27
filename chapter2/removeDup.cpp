#include <iostream>
#include <map>
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
/*
  remove duplicate nodes using hash map
  space complexity O(n)
  time complexity O(n)
*/
void remove_dup(ListNode* head){
  map<int, int> hash;
  if(head == nullptr) return;
  ListNode* curr = head->next;
  ListNode* prev = head;
  hash[head->val] = 1;
  while(curr != nullptr){
    if(hash.find(curr->val) == hash.end()){
      hash[curr->val] = 1;
      prev = prev->next;
      curr = curr->next;
    }else{
      prev->next = curr->next;
      ListNode* temp = curr;
      curr = curr->next;
      delete temp;
    }
  }
}
/*
  remove duplicate nodes without extra space
  time complexity: O(n^2)
  space complexity: O(1)
 */
void remove_inplace(ListNode* head){
  ListNode* curr = head;
  if(head == nullptr) return;
  while(curr != nullptr){
    ListNode* dup = curr->next;
    ListNode* prev = curr;
    while(dup != nullptr){
      if(dup->val == curr->val){
        prev->next = dup->next;
	delete dup;
	dup = prev->next;
      }else{
	prev = prev->next;
	dup = dup->next;
      }
    }
    curr = curr->next;
  }
}

void printList(ListNode* head){
  ListNode* curr = head;
  while(curr != nullptr){
    cout<<curr->val<<"->";
    curr = curr->next;
  }
  cout<<endl;
}

int main(){
  ListNode * head = new ListNode(2);
  push_front(head, 3);
  push_front(head, 4);
  push_front(head, 4);
  push_front(head, 3);
  printList(head);
  remove_inplace(head);
  //  remove_dup(head);
  printList(head);
  delete head;
  return 0;
}

