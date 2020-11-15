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

bool check(TreeNode* s, TreeNode* t){
    if(!s && !t) return true; 
    if(!s || !t) return false; 
    if(s -> data != t -> data) return false; 
    return check(s -> left, t -> left) && check(s -> right, t -> right); 
}
bool isSubTree(TreeNode* s, TreeNode* t){
    if(!s || !t) return false; 
    else return check(s, t) || isSubTree(s -> left, t) || isSubTree(s -> right, t); 
}

int main(){
    /* Problem 4.10 => Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an
algorithm to determine if T2 is a subtree of Tl.*/
    vector<int> arr = {1,2,3,4,5,6};

    TreeNode* head = MinimalTree(arr, 0, arr.size() - 1);
    print2D(head);

}