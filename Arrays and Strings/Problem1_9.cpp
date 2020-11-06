#include <iostream>
using namespace std; 

string leftRotation(string s, int d){
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
    return s;
}

bool isSubstring(string A, string B){
    for(int i = 0; i < A.length(); i++) if(leftRotation(A, i) == B) return true; 
    return false; 
}

int main(){

    /* Problem 1.9: Assumeyou have a method isSubstringwhich checks if one word is a substring of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one call to isSubstring (e.g.,"waterbottle" is a rotation of"erbottlewat").
    */ 

   string A = "waterbottle"; 
   string B = "erbottlewat"; 

   if(isSubstring(A, B)) cout << "True" << endl; 
   else cout << "False" << endl;
}