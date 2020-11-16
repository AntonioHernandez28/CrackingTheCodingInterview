#include <iostream> 
#include <vector> 
using namespace std; 

int diffWays(int n){
    vector<int> dp(n+1); 
    dp[0] = 1; 
    dp[1] = 1; 
    dp[2] = 2; 
    for(int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; 
    return dp[n];
}

int main(){
    /* Problem 8.1 =>  Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. 
    Implement a method to count how many possible ways the child can run up the stairs.*/ 
    cout << diffWays(4) << endl;
}