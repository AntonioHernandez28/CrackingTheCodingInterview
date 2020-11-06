#include <iostream>
#include <unordered_map>
using namespace std; 

bool OneWay(string A, string B){
    unordered_map<char, int> hashMap; 
    string large = A.length() >= B.length() ? A:B;
    string small = large == A ? B:A; 

    for(auto x:large) if(hashMap.find(x) == hashMap.end()) hashMap[x] = 1; 
    else hashMap[x]++; 

    for(auto y:small) if(hashMap.find(y) != hashMap.end()) hashMap[y]--; 

    bool flag = false; 

    for(auto z:hashMap){
        if(z.second > 0 && !flag) flag = true; 
        else if (z.second > 0 && flag == true) return false; 
    }
    return true; 

}

int main(){
    /* Problem 1.5: One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.
    */ 
   string A = "pale"; 
   string B = "ple"; 
   string C = "bake"; 
   string D = "pales"; 
   string E = "bales";

   if(OneWay(A, E)) cout << "True" << endl; 
   else cout << "False" << endl;
}