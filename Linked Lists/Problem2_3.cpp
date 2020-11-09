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

void DeleteMiddleNode(ListNode* mid){
    mid -> val = mid -> next -> val;
    mid -> next = mid -> next -> next; 
}

int main(){
    /* Problem 2.3 => Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
EXAMPLE
lnput:the node c from the linked lista->b->c->d->e->f
Result: nothing is returned, but the new linked list looks likea->b->d->e- >f */

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

    DeleteMiddleNode(head2); 

    printList(head);

}