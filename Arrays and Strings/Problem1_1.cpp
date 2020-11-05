#include <iostream> 
#include <unordered_set> 
using namespace std; 

//Problem 1.1 Determine if a string has all unique characters 
bool hasUniqueChars(string s){
    unordered_set<char> hashSet; 
    for(auto x:s) if(hashSet.find(x) == hashSet.end()) hashSet.insert(x); 
    else return false; 
    return true; 
}

int main(){

    // Problem 1
    if(hasUniqueChars("holakdisa")) cout << "True" << endl; 
    else cout << "False" << endl; 
    
}

/* Falta solucionarlo con el follow up que es SIN data structures extra */