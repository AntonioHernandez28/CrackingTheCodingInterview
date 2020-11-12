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

vector<vector<int>> LevelByLevel(TreeNode* root){
    vector<vector<int>> res; 
    if(!root) return res; 
    queue<TreeNode*> q; 
    q.push(root); 

    while(!q.empty()){
        int n = q.size(); 
        vector<int> temp;
        for(int i = 0; i < n; i++){ 
            TreeNode* currentNode = q.front(); 
            temp.push_back(currentNode -> data); 
            q.pop();
            if(currentNode -> left) q.push(currentNode -> left); 
            if(currentNode -> right) q.push(currentNode -> right); 
        }
        res.push_back(temp); 
    }
    return res; 
}

int main(){
    /* Problem 4.2: Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height. */
    vector<int> arr = {1,2,3,4,5,6};

    TreeNode* head = MinimalTree(arr, 0, arr.size() - 1);

    print2D(head); 
    vector<vector<int>> res = LevelByLevel(head); 
    for(auto x:res){
        for(auto y:x) cout << y << " "; 
        cout << endl; 
    }

}