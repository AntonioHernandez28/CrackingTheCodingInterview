#include <iostream> 
#include <vector> 
#include <queue>
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
    nuevoNodo -> data = mid; 
    nuevoNodo -> left = MinimalTree(arr, begin, mid - 1); 
    nuevoNodo -> right = MinimalTree(arr, mid + 1, end); 

    return nuevoNodo; 
}

int height(TreeNode* root){
    if(!root) return 0; 
    return 1 + max(height(root -> left), height(root -> right)); 
}

bool isBalanced(TreeNode* root){
    int Left = height(root -> left); 
    int Right = height(root -> right); 
    return abs(Left - Right) <= 1 ? true:false; 
}

int main(){
    /* Problem 4.4: Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes 
    of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one. */
    vector<int> arr = {1,2,3,4,5};

    TreeNode* head = MinimalTree(arr, 0, arr.size() - 1);
    print2D(head);
    if(isBalanced(head)) cout << "True" << endl; 
    else cout << "False" << endl; 
}