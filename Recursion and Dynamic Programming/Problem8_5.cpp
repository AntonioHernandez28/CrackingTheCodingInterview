#include <iostream>
#include <vector>
using namespace std; 

int multiply(int A, int B, int cnt){
    if(cnt == B) return A; 
    else return A + multiply(A, B, cnt + 1); 
}

int main(){
    /* Problem 8.5 => Recursive Multiply: Write a recursive function to multiply two positive integers without 
    using the *operator.You can use addition, subtraction, and bit shifting, 
    but you should minimize the number of those operations.
    */

   cout << multiply(10, 10, 1); 
}