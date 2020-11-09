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

ListNode* detectMergedLists(ListNode* A, ListNode* B){
    int sizeA = 0; 
    int sizeB = 0; 
    ListNode* tailA; 
    ListNode* tailB; 
    ListNode* headA = A; 
    ListNode* headB = B; 

    while(A){
        sizeA++; 
        if(!A -> next) tailA = A; 
        A = A -> next; 
    }
    while(B){
        sizeB++; 
        if(!B -> next) tailB = B; 
        B = B -> next; 
    }

    if(tailA != tailB) return NULL; 

    ListNode* shortList = sizeA <= sizeB ? headA:headB; 
    ListNode* LargeList = shortList == headA ? headB:headA; 
    int diff = abs(sizeA - sizeB); 

    for(int i = 0; i < diff; i++) LargeList = LargeList -> next; 

    while(LargeList != shortList){
        LargeList = LargeList -> next; 
        shortList = shortList -> next; 
    }

    return LargeList; 

}

int main(){
    /* Problem 2.7:  Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the inter­ secting node. Note that the intersection is defined based on reference, 
    not value.That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting. */

    ListNode* head = new ListNode(); 
    head -> val = 4; 

    ListNode* head1 = new ListNode(); 
    head1 -> val = 1; 

    ListNode* head2 = new ListNode(); 
    head2 -> val = 8; 

    ListNode* head3 = new ListNode(); 
    head3 -> val = 4; 

    ListNode* head4 = new ListNode(); 
    head4 -> val = 5; 

    ListNode* head5 = new ListNode(); 
    head4 -> val = 5; 

    ListNode* head6 = new ListNode(); 
    head4 -> val = 6; 

    ListNode* head7 = new ListNode(); 
    head4 -> val = 1; 

    head -> next = head1; 
    head1 -> next = head2; 
    head2 -> next = head3; 
    head3 -> next = head4; 
    
    head5 -> next = head6; 
    head6 -> next = head7; 
    head7 -> next = head2; 

    ListNode* res = detectMergedLists(head, head5); 
    if(res) cout << res -> val << endl; 
    else cout << "NULL" << endl; 

}