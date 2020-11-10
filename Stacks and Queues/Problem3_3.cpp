#include <iostream> 
#include <stack> 
#include <vector>
using namespace std;

struct SetOfStacks{
    vector<stack<int>> stacks; 
    int MaxNumber; 
};

SetOfStacks globalSet; 

void push(int A){
    if(globalSet.stacks.size() == 0){
        stack<int> s; 
        globalSet.stacks.push_back(s); 
        s.push(A);
    }
    else{
        for(int i = 0; i < globalSet.stacks.size(); i++){
            if(globalSet.stacks[i].size() < globalSet.MaxNumber) globalSet.stacks[i].push(A); 
            else if(globalSet.stacks[i].size() >= globalSet.MaxNumber && i == globalSet.stacks.size() - 1){
                stack<int> s; 
                globalSet.stacks.push_back(s); 
                globalSet.stacks[i+1].push(A); 
            }
        }
    }
}

int pop(){
    if(globalSet.stacks[0].size() > 0){ 
        int ret = globalSet.stacks[0].top(); 
        globalSet.stacks[0].pop();
        return ret; 
    }
    else{
        globalSet.stacks.erase(globalSet.stacks.begin()); 
        int ret = globalSet.stacks[0].top(); 
        globalSet.stacks[0].pop(); 
        return ret; 
    }
    return -1; 
}
int main() {
    /*  Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
        composed of several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack (that is, pop() 
        should return the same values as it would if there were just a single stack).
        FOLLOW UP
        ImplementafunctionpopAt(int index)whichperformsapopoperationonaspecificsub-stack.   ! falta testing ! */ 
}