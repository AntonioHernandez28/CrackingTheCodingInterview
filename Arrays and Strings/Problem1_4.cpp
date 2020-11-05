#include <iostream>
#include <unordered_map>
using namespace std; 

bool isPalindromePermutation(string s){
    unordered_map<char, int> hashMap; 
    for(auto x:s){
        if(x != ' '){
            if(hashMap.find(tolower(x)) == hashMap.end()) hashMap[tolower(x)] = 1; 
            else hashMap[tolower(x)]++;
        }
    } 
    
    bool OneOccupied = false;
    if(hashMap.size() == 1) return true; 
    else{
        for(auto x:hashMap){
            if(x.second %2 != 0 && OneOccupied == false) OneOccupied = true; 
            else if(x.second %2 != 0  && OneOccupied == true) return false; 
            else if(x.second % 2 != 0) return false; 
        }
    }
    return true; 
}

int main() {
    /* Problem 1.4 Given a string, write a function to check if it is a permutation of a palin­ drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
    */ 
   
   string s = "aaaaaaaaccbbeee"; 
   if(isPalindromePermutation(s)) cout << "True" << endl; 
   else cout << "False" << endl;
}