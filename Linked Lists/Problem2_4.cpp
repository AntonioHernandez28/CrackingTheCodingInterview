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

ListNode* Partition(ListNode* head, int K){
    ListNode* BeforeListStart = new ListNode();
    ListNode* BeforeListEnd; 
    ListNode* AfterListStart =  new ListNode();
    ListNode* AfterListEnd; 
    ListNode* curr = head; 
    cout << "PTM" << endl;
    BeforeListStart -> next = BeforeListEnd; 
    AfterListStart -> next = AfterListEnd; 
    
    while(curr){
        if(curr -> val < K){
            cout << "Min -> " << curr -> val << endl; 
            BeforeListEnd -> next = curr; 
            BeforeListEnd = BeforeListEnd -> next; 
        }
        else{
            cout << "Max -> " << curr -> val << endl;
            AfterListEnd -> next = curr; 
            AfterListEnd = AfterListEnd -> next; 
        }
        curr = curr -> next; 
    }
    
    BeforeListEnd -> next = AfterListStart -> next; 

    return BeforeListStart;
    
}
int main(){
    /* Problem 2.4 => Partition: Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the 
    list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to 
    appear between the left and right partitions.
    Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.

    */

    
    ListNode* head = new ListNode(); 
    head -> val = 1; 

    ListNode* head1 = new ListNode(); 
    head1 -> val = 4; 

    ListNode* head2 = new ListNode(); 
    head2 -> val = 3; 

    ListNode* head3 = new ListNode(); 
    head3 -> val = 2; 

    ListNode* head4 = new ListNode(); 
    head4 -> val = 5; 

    ListNode* head5 = new ListNode(); 
    head5 -> val = 2; 



    head5 -> next = NULL;

    head -> next = head1;  

    head1 -> next = head2;

    head2 -> next = head3;

    head3 -> next = head4;

    printList(Partition(head, 3)); 
}