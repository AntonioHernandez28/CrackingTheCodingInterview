#include <iostream>
#include <stack> 
#include <queue> 
using namespace std; 
/* Solution in book is set to be O(n^2) and O(n), however, it is a good oportunity to work with priotrity queue instead, which even also has a better complexity time */

stack<int> sort(stack<int> s){
    priority_queue<int> pq; 
    while(!s.empty()){
        pq.push(s.top()); 
        s.pop();
    }
    while(!pq.empty()){
        s.push(pq.top()); 
        pq.pop(); 
    }

    return s; 
}

int main(){
    /*  Problem 3.5 = Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, 
    but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty. */
    stack<int> s; 
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(6);

    stack<int> r = sort(s); 

    while(!r.empty()){
        cout << r.top() << endl;
        r.pop(); 
    }
    

}