#include <iostream>
#include <unordered_map>
using namespace std; 

bool isPermutation(string A, string B){
    unordered_map<char, int> hashMap; 
    if(A.length() != B.length()) return false; 
    for(auto x:A) if(hashMap.find(x) == hashMap.end()) hashMap[x] = 1; 
    else hashMap[x]++; 

    for(auto y:B) if(hashMap.find(y) != hashMap.end()) hashMap[y]--; 

    for(auto z:hashMap) if(z.second != 0) return false; 
    return true; 
}

int main() {
    /* Problem 1.2: Given two strings,write a method to decide if one is a permutation of the
other. */
    string A = "ABCD"; 
    string B = "CBDA"; 
    string C = "ABCA"; 

    if(isPermutation(A, C)) cout << "True" << endl; 
    else cout << "False" << endl; 
}