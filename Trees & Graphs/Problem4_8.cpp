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

bool searchNode(TreeNode* root, int N, vector<int> &path){
    if(!root) return false;
    path.push_back(root -> data); 
    if(root -> data == N) return true; 
    if(searchNode(root -> left, N, path) || searchNode(root -> right, N, path)) return true; 
    path.pop_back(); 
    return false; 
}

int LCA(TreeNode* head, int A, int B){
    vector<int> PathA, PathB; 
    bool resA = searchNode(head, A, PathA); 
    bool resB = searchNode(head, B, PathB); 

    if(!resA) return resB; 
    if(!resB) return resA; 

    for(int i = 0; i < max(PathA.size(), PathB.size()); i++){
        if(PathA.size() < i+1) return PathB[i]; 
        if(PathB.size() < i+1) return PathA[i]; 
        if(PathA[i+1] != PathB[i+1]) return PathA[i]; 
    }

    return -1; 


}

int main(){
    /* Problem 4.8: LCA.  CHECK THE SEARCH NODE FUNC COPY IN NOTES OR LEARN IT DEEPLY IT CAN BE VERY USEFUL*/
    vector<int> arr = {1,2,3,4,5,6};

    TreeNode* head = MinimalTree(arr, 0, arr.size() - 1);
    print2D(head);

    cout << LCA(head, 3, 5) << endl; 
}