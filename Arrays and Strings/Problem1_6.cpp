
#include <iostream>
#include <vector>
using namespace std; 

string stringCompressor(string A){
    string result = "";
    vector<pair<char, int>> currentTuples; 
    int Reps = 1; 
    for(int i = 0; i < A.length(); i++){
        while(A[i] == A[i+1]){ 
            Reps++;
            i++; 
        } 
        currentTuples.push_back(make_pair(A[i], Reps)); 
        Reps = 1; 
    } 
    for(auto x:currentTuples) result += (x.first + to_string(x.second)); 
    return result.length() < A.length() ? result:A; 
}

int main(){
    /* String Compression: Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).
    */
   string A = "aabcccccaaa";
   string B = "abcdefghi"; 

   cout << stringCompressor(A) << endl;
}