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

ListNode* sum(ListNode* A, ListNode* B){
    ListNode* resultSum = new ListNode(); 
    ListNode* headResult = resultSum; 
    int carry = 0; 
    while(A != NULL || B != NULL){
        ListNode* newNode = new ListNode(); 
        int x = A == NULL ? 0 : A -> val; 
        int y = B == NULL ? 0 : B -> val;
        int total = x + y + carry; 
        carry = total / 10; 
        newNode -> val = total % 10; 
        resultSum -> next = newNode; 
        resultSum = resultSum -> next; 

        if(A) A = A->next; 
        if(B) B = B -> next; 
    }

    if(carry > 0){
        ListNode* newNode = new ListNode(); 
        newNode -> val = carry; 
        resultSum -> next = newNode; 
    }


    return headResult -> next; 
}

int main(){
    /*  Problem 2.5: Sum Lists: You have two numbers represented by a linked list, where each node contains a single digit.The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
        EXAMPLE
        Input:(7-> 1 -> 6) + (5 -> 9 -> 2).Thatis,617 + 295. Output:2 -> 1 -> 9.Thatis,912.

    */

    
    ListNode* head = new ListNode(); 
    head -> val = 7; 

    ListNode* head1 = new ListNode(); 
    head1 -> val = 1; 

    ListNode* head2 = new ListNode(); 
    head2 -> val = 6; 

    ListNode* head3 = new ListNode(); 
    head3 -> val = 5; 

    ListNode* head4 = new ListNode(); 
    head4 -> val = 9; 

    ListNode* head5 = new ListNode(); 
    head5 -> val = 2; 



    head5 -> next = NULL;

    head -> next = head1;  

    head1 -> next = head2;

    head2 -> next = NULL;

    head3 -> next = head4;

    head4 -> next = head5;

    printList(sum(head, head3));


}