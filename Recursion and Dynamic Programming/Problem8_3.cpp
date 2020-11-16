#include <iostream> 
#include <vector>
using namespace std; 

int binarySearch(vector<int> nums, int start, int end){
    if(start <= end){
        int mid = (start + end)/2;
        if(nums[mid] == mid) return mid; 
        if(nums[mid] < mid) return binarySearch(nums, mid + 1, end); 
        else return binarySearch(nums, start, mid - 1); 
    }
    return -1;
}
bool magicIndex(vector<int> nums){
    if(binarySearch(nums, 0, nums.size() - 1) == -1) return false; 
    else return true; 
}

int main(){
    /* Problem 8.3 => Magic Index: A magic index in an array A[ 0••• n -1] is defined to be an index such that A[ i] = i. Given a sorted array of distinct integers, 
    write a method to find a magic index, if one exists, in array A.*/
    vector<int> A = {-1, 1, 2, 3, 5, 6}; 
    //               0   1  2  3  4   5
    if(magicIndex(A)) cout << "true" << endl; 
    else cout << "false" << endl;
}