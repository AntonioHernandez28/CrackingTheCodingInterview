#include <iostream>
using namespace std; 

void MoveString(string &s, int size, int pos){
    for(int i = size; i > pos; i--) swap(s[i], s[i+2]); 
}
string URLify(string s, int size){
    //MoveString(s, si); 
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){ 
            MoveString(s, size - 1, i); 
            s[i] = '%'; 
            s[i+1] = '2'; 
            s[i+2] = '0'; 
            i+=2;
            size += 2;
        }
    }
    return s; 
}

int main(){
    /* Problem 1.3: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters,and that you are given the "true" length of the string. (Note: If implementing in Java,please use a character array so that you can perform this operation in place.)
EXAMPLE
Input: "Mr John Smith ", 13 Output: "Mr%20John%20Smith"
    */ 
   string input = "Mr John Smith    "; 
   int realSize = 13; 
   cout << URLify(input, realSize) << endl; 
}