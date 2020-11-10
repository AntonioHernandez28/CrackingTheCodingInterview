#include <iostream> 
#include <stack>
using namespace std; 

int MinimumInStack(stack<int> s){
    int minNumber = 9999; 
    while(!s.empty()){
        minNumber = min(minNumber, s.top()); 
        s.pop(); 
    }
    return minNumber; 
}
int main(){
    /* Problem 3.2: How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? Push, pop and min should all operate in 0(1) time.*/
    stack<int> myStack; 
    myStack.push(8); 
    myStack.push(8); 
    myStack.push(8); 
    myStack.push(8); 
    myStack.push(8); 
    myStack.push(8); 
    cout << MinimumInStack(myStack) << endl; 
}