#include <iostream>
#include <vector>
using namespace std; 

void getSubsets(vector<int> nums, vector<vector<int>> &res, vector<int> current, int index){
    res.push_back(current); 
    for(int i = index; i < nums.size(); i++){
        current.push_back(nums[i]); 
        getSubsets(nums, res, current, i+1); 
        current.pop_back(); 
    }
    return; 
}
// O(2^n)
int main(){
    /* Problem 8.4 => Power Set: Write a method to return all subsets of a set.
    */
   vector<int> nums = {1,2,3}; 
   vector<vector<int>> res; 
   vector<int> curr; 
   getSubsets(nums, res, curr, 0); 
   for(auto x:res){
       for(int y:x) cout << y << " "; 
       cout << endl; 
   }
}