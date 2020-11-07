#include <iostream>
using namespace std;

struct ListNode{
    int val; 
    ListNode* next; 
};

void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head -> next; 
    }
}

ListNode* KthToLast(ListNode* head, int k){
    ListNode* temp = head; 
    ListNode* curr = head; 

    for(int i = 0; i < k; i++) curr = curr -> next; 

    if(!curr) return NULL; 

    while(curr -> next){
        curr = curr -> next; 
        temp = temp -> next; 
    }

    return temp; 
    
}

int main(){
    /* Problem 2.2:  Implement an algorithm to find the kth to last element of a singly linked list. */

    ListNode* head = new ListNode(); 
    head -> val = 1; 

    ListNode* head1 = new ListNode(); 
    head1 -> val = 2; 

    ListNode* head2 = new ListNode(); 
    head2 -> val = 3; 

    ListNode* head3 = new ListNode(); 
    head3 -> val = 4; 

    ListNode* head4 = new ListNode(); 
    head4 -> val = 5; 



    head4 -> next = NULL;

    head -> next = head1;  

    head1 -> next = head2;

    head2 -> next = head3;

    head3 -> next = head4;

 

    if(KthToLast(head, 5)) cout << KthToLast(head, 5) -> val << endl; 
    else cout << "NULL" << endl;
}
/*
list = 1 -> 2 -> 3 -> 4 -> 5 -> null
nthToLast(list, 0) = 5
nthToLast(list, 1) = 4
nthToLast(list, 4) = 1
nthToLast(list, 5) = null

*/