#include <iostream> 
#include <vector>
using namespace std; 

int numberPaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n)); 
    dp[0][0] = 1; 
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) continue; 
            else if(i == 0) dp[i][j] = dp[i][j-1]; 
            else if(j == 0) dp[i][j] = dp[i-1][j]; 
            else dp[i][j] = dp[i][j-1] + dp[i-1][j]; 
        }
    }
    return dp[m-1][n-1]; 
}

int main(){
    /* Problem 8.2 => Robot in a Grid: Imagine a robot sitting on the upper left corner of grid with r rows and c columns. The robot can only move in two directions, right and down, 
    but certain cells are "off limits" such that the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to the bottom right.*/ 
    cout << numberPaths(3,7) << endl;
}