#include <iostream>
#include <stack>
#include <vector> 
using namespace std;

void ThreeArrays(vector<int> A, int numArray){
    int length = A.size()/3; 
    int stackA = 0;
    int stackB = stackA + length; 
    int stackC = stackB + length; 

    if(numArray == 1) for(int i = 0; i < length; i++) cout << A[i] << endl; 
    else if(numArray == 2) for(int i = stackB; i < stackC; i++) cout << A[i] << endl; 
    else for(int i = stackC; i < A.size(); i++) cout << A[i] << endl; 

    return; 

}
int main(){
    /* Problem 3.1: Three in One: Describe how you could use a single array to implement three stacks. Other funcs can be done with simples swaps*/
    vector<int> A = {1,2,3,4,5,6};  
    ThreeArrays(A, 1); 
    cout << endl; 
    ThreeArrays(A, 2); 
    cout << endl; 
    ThreeArrays(A, 3); 
}