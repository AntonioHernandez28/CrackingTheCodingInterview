#include <iostream> 
#include <vector> 
#include <random>
#include <time.h>
#include <cstdlib>

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

void dfsSize(TreeNode* root, int &val){
    if(!root) return; 
    dfsSize(root -> left, val); 
    val++; 
    dfsSize(root -> right, val); 
}
int counter = 0; 
void dfs(TreeNode* root, int val, int &res){
    if(!root) return;
    dfs(root -> left, val, res); 
    cout << val << " - " << counter << endl; 
    if(val == counter) res = root -> data; 
    counter++; 
    dfs(root -> right, val, res); 
}

int randomNode(TreeNode* root){
    srand ( time(NULL) );
    int size = 0; 
    int res = -1; 
    dfsSize(root, size); 
    int random = rand() % size;
    cout << random << endl;
    dfs(root, random, res); 
    return res; 
}
int main(){
    /* Problem 4.11 => Random Node: You are implementing a binary tree class from scratch which, in addition to insert, find, and delete, has a method getRandomNode() which returns a random node from the tree. All nodes should be equally likely to be chosen. 
    Design and implement an algorithm for getRandomNode, and explain how you would implement the rest of the methods*/
    vector<int> arr = {1,2,3,4,5,6};

    TreeNode* head = MinimalTree(arr, 0, arr.size() - 1);
    print2D(head);
    cout << randomNode(head) << endl; 

}