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

void DFS(TreeNode* root, vector<int> &arr){
    if(!root) return; 
    DFS(root -> left, arr); 
    arr.push_back(root -> data); 
    DFS(root -> right, arr);
    return; 
}

bool isBST(TreeNode* root){
    vector<int> arr; 
    DFS(root, arr); 
    for(int i = 0; i < arr.size() - 2; i++) if(arr[i] > arr[i+1]) return false; 
    return true;
}
int main(){
    /* Problem 4.5: Validate BST: Implement a function to check if a binary tree is a binary search tree. */
    vector<int> arr = {6,5,3,8,1,2};

    TreeNode* root = MinimalTree(arr, 0, arr.size() - 1);
    print2D(root);

    if(isBST(root)) cout << "true" << endl; 
    else cout << "false" << endl; 
}