#include <iostream>
#include <vector> 
using namespace std; 

void zeroing(vector<vector<int>> &arr, int column, int row){
    for(int i = 0; i < arr[0].size(); i++) arr[column][i] = 0; 
    for(int i = 0; i < arr.size(); i++) arr[i][row] = 0; 
}

void transformArray(vector<vector<int>> &array){
    vector<pair<int, int>> pos; 
    for(int i = 0; i < array.size(); i++)
        for(int j = 0; j < array[0].size(); j++) if(array[i][j] == 0) pos.push_back(make_pair(i, j));

    for(auto x:pos) zeroing(array, x.first, x.second);  

}

int main() {
    /*  Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0. */ 

    vector<vector<int>> array = {{1,0,3}, {4,5,6}, {7,8,9}}; 

    transformArray(array); 

    for(auto x:array){
        for(auto y:x) cout << y << " "; 
        cout << endl; 
    }

}