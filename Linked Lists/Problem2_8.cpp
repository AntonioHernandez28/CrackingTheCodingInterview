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

ListNode* cycleNode(ListNode* A){
    ListNode* fast = A -> next; 
    ListNode* slow = A;
    while(fast && slow && fast -> next){
        if(fast == slow) break; 
        fast = fast -> next -> next; 
        slow = slow -> next; 
    }

    if(slow != fast) return NULL; 

    slow = A; 

    while(slow != fast){
        slow = slow -> next; 
        fast = fast -> next -> next; 
    }

    return slow; 
}

int main(){
    /* Problem 2.8:  Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
    beginning of the loop.
        DEFINITION
        Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
        EXAMPLE
        Input: 1 -> 2 -> 3 -> 4 -> 5 -> 2[thesameCasearlier]
        Output: 2 */

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
    
    head4 -> next = head1;

    head -> next = head1;  

    head1 -> next = head2;

    head2 -> next = head3;

    head3 -> next = head4;

    //printList(head);

    ListNode* res = cycleNode(head); 

    if(!res) cout << "NULL NO CYCLE" << endl; 
    else cout << res -> val << endl; 

}