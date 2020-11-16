#include <iostream>
#include <vector>
using namespace std; 

void permutations(string a, int l, int r, vector<string> &res){
    if(l == r) res.push_back(a); 
    else{
        for(int i = l; i <= r; i++){
            swap(a[l], a[i]); 
            permutations(a, l+1, r, res); 
            swap(a[l], a[i]); 
        }
    }
}


int main(){
    /* Problem 8.7 => Permutations without Dups: Write a method to compute all 
    permutations of a string of unique characters.
    */
   string a = "abbc"; 
   vector<string> res; 
   permutations(a, 0, a.size() - 1, res); 
   for(auto x:res){
       for(auto y:x) cout << y; 
       cout << endl; 
   }
}