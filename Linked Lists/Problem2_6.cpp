#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
    char val; 
    ListNode* next; 
};

void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head -> next; 
    }
}

bool isPalindrome(ListNode* A){
    stack<char> myStack; 
    ListNode *curr = A; 
    while(curr){
        myStack.push(curr -> val); 
        curr = curr -> next; 
    }
    while(!myStack.empty()){
        if(A -> val != myStack.top()) return false; 
        myStack.pop(); 
        A = A -> next; 
    }
    return true; 
}

int main(){
    /* Problem 2.6 = Palindrome: Implement a function to check if a linked list is a palindrome.

    */

    
    ListNode* head = new ListNode(); 
    head -> val = 'A'; 

    ListNode* head1 = new ListNode(); 
    head1 -> val = 'N'; 

    ListNode* head2 = new ListNode(); 
    head2 -> val = 'N'; 

    ListNode* head3 = new ListNode(); 
    head3 -> val = 'N'; 

    ListNode* head4 = new ListNode(); 
    head4 -> val = 'E'; 

    ListNode* head5 = new ListNode(); 
    head5 -> val = 'A'; 



    head5 -> next = NULL;

    head -> next = head1;  

    head1 -> next = head2;

    head2 -> next = head3;

    head3 -> next = head4;

    head4 -> next = head5; 

    if(isPalindrome(head)) cout << "true" << endl;
    else cout << "false" << endl;

}