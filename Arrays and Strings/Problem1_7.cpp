#include <iostream> 
#include <vector> 
using namespace std; 

/* REPASAR OJO REPASAR */ 

void transposeMatrix(vector<vector<int>> &array){
    for(int i = 0; i < array.size(); i++)
        for(int j = i; j < array[0].size(); j++)
            swap(array[i][j], array[j][i]); 
}

void rotateMatrix(vector<vector<int>> &array){
    transposeMatrix(array); 
    for(int i = 0; i < array.size(); i++){
        for(int j = 0, k = array.size() - 1; j < k; j++, k--) swap(array[j][i], array[k][i]); 
    }
}


int main(){
    /* Problem 1.7: Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
Hints:#51, #100 
    1 2 3 
    4 5 6 
    7 8 9

    3 6 9 
    2 5 8
    1 4 7

    Approach: Tasponse matrix and theeeeen reverse columns of transposed matrix (columns NOT rows)

    REPASAR
*/ 

    vector<vector<int>> Array = {{1,2,3}, {4,5,6}, {7,8,9}}; 

    rotateMatrix(Array); 

    for(auto x:Array){
        for(auto y:x) cout << y << " "; 
        cout << endl; 
    }

}