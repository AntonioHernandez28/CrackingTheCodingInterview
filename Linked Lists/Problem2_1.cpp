#include <iostream>
#include <unordered_set>
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

void deleteDuplicates(ListNode* head){
    unordered_set<int> hashSet; 
    ListNode* dummy = new ListNode(); 
    dummy->next = head; 
    ListNode *current = head;

    while(current){
        if(hashSet.find(current -> val) == hashSet.end()){ 
            hashSet.insert(current -> val);
            dummy = current; 
            current = current -> next; 
        }
        else {
            while(current && hashSet.find(current -> val) != hashSet.end()) current = current -> next; 
            dummy -> next = current; 
        }

    }
    
    return; 
}

int main(){
    /* Problem 2.1: Write code to remove duplicates from an unsorted linked list. */

    ListNode* head = new ListNode(); 
    head -> val = 1; 

    ListNode* head1 = new ListNode(); 
    head1 -> val = 1; 

    ListNode* head2 = new ListNode(); 
    head2 -> val = 2; 

    ListNode* head3 = new ListNode(); 
    head3 -> val = 2; 

    ListNode* head4 = new ListNode(); 
    head4 -> val = 2; 

    ListNode* head5 = new ListNode(); 
    head5 -> val = 3;

    head5 -> next = NULL;

    head -> next = head1;  

    head1 -> next = head2;

    head2 -> next = head3;

    head3 -> next = head4;

    head4 -> next = head5;

    deleteDuplicates(head); 
    printList(head);


}