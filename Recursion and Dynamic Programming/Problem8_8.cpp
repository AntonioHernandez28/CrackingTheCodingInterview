#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std; 

unordered_set<string> set; 

void permutations(string a, int l, int r, vector<string> &res){
    if(l == r && set.find(a) == set.end()){
        res.push_back(a); 
        set.insert(a); 
    }
    else{
        for(int i = l; i <= r; i++){
            swap(a[l], a[i]); 
            permutations(a, l+1, r, res); 
            swap(a[l], a[i]); 
        }
    }
}


int main(){
    /* 
Permutations with Dups: Write a method to compute all permutations of a string whose charac­ ters are not necessarily unique. 
The list of permutations should not have duplicates.
    */
      string a = "abbc"; 
   vector<string> res; 
   permutations(a, 0, a.size() - 1, res); 
   for(auto x:res){
       for(auto y:x) cout << y; 
       cout << endl; 
   }
}