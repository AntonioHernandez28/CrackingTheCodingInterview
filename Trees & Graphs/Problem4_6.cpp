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
TreeNode* input; 
void search(TreeNode* root){
    if(!root) return; 
    search(root -> left); 
    if(root -> data == 3) input = root; 
    search(root -> right); 
    return; 
}
int previo = -1; 
void InOrder(TreeNode* root, int given, int &res){
    if(!root) return; 
    InOrder(root -> left, given, res); 
    if(previo == given){ 
        res = root -> data; 
        previo = -1;
    }
    else previo = root -> data; 
    InOrder(root -> right, given, res); 
    return;
}
int inOrderSuccessor(TreeNode* root, TreeNode* given){
    int res = -1; 
    InOrder(root, given -> data, res); 
    return res; 
}
int main(){
    /* Problem 4.6:  Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. You may assume that each node has a link to its parent.*/
    vector<int> arr = {1,2,3,4,5,6};

    TreeNode* root = MinimalTree(arr, 0, arr.size() - 1); 
    print2D(root); 
    search(root); 
    cout << inOrderSuccessor(root, input) << endl; 

}