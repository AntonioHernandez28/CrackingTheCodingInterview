#include <iostream> 
#include <vector> 
using namespace std; 
#define COUNT 10

struct TreeNode{
    int data; 
    TreeNode* left; 
    TreeNode* right; 
}; 

void print2DUtil(TreeNode *root, int space)  
{  

    if (root == NULL)  
        return;  
  
    space += COUNT;  
  
    print2DUtil(root->right, space);  
  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  
  
    print2DUtil(root->left, space);  
}  
   
void print2D(TreeNode *root)  
{    
    print2DUtil(root, 0);  
}  

TreeNode* MinimalTree(vector<int> arr, int begin, int end){
    if(end < begin) return NULL;
    int mid = (begin + end)/2; 
    TreeNode* nuevoNodo = new TreeNode(); 
    nuevoNodo -> data = arr[mid]; 
    nuevoNodo -> left = MinimalTree(arr, begin, mid - 1); 
    nuevoNodo -> right = MinimalTree(arr, mid + 1, end); 

    return nuevoNodo; 
}

void PathSums(TreeNode* root, int sum, int target, vector<vector<int>> &Paths, vector<int> &currentPath){
    if(!root) return; 
    sum += root -> data; 
    currentPath.push_back(root -> data); 
    if(sum == target)Paths.push_back(currentPath); 
    PathSums(root -> left, sum, target, Paths, currentPath); 
    PathSums(root -> right, sum, target, Paths, currentPath); 
    currentPath.pop_back(); 
}

int main(){
    /* Problem 4.12  Paths with Sum: You are given a binary tree in which each node contains an integer value (which might be positive or negative). 
    Design an algorithm to count the number of paths that sum to a given value. */
    vector<int> arr = {1,2,3,4,5,6};

    TreeNode* root = MinimalTree(arr, 0, arr.size() - 1);
    print2D(root); 
    vector<vector<int>> res;
    vector<int> curr;   
    PathSums(root, 0, 12, res, curr); 
    for(auto x:res){
        for(auto y:x) cout << y << " "; 
        cout << endl; 
    }

}