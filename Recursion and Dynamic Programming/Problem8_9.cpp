#include <iostream>
#include <vector>
using namespace std; 

void printParenthesesPairs(int pos, int n, int open, int close){
   static char str[1000];
   if(close == n) {
      cout<<str<<endl;
      return;
   }
   else {
      if(open > close) {
         str[pos] = '}';
         printParenthesesPairs(pos+1, n, open, close+1);
      }
      if(open < n) {
         str[pos] = '{';
         printParenthesesPairs(pos+1, n, open+1, close);
      }
   }
}


int main(){
    /*
     Problem 8.9 => Parens: Implement an algorithm to print all valid (e.g., properly opened and closed) 
     combinations of n pairs of parentheses.
EXAMPLE
Input: 3
Output: ((())), (()()), (())(), ()(()), ()()()
    */
}