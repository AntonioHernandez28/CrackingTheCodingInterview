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

vector<vector<int> > findAllSeq(TreeNode *ptr)
{
    if (ptr == NULL) {
        vector<int> seq;
        vector<vector<int> > v;
        v.push_back(seq);
        return v;
    }


    if (ptr -> left == NULL && ptr -> right == NULL) {
        vector<int> seq;
        seq.push_back(ptr -> val);
        vector<vector<int> > v;
        v.push_back(seq);
        return v;
    }

    vector<vector<int> > results, left, right;
    left  = findAllSeq(ptr -> left);
    right = findAllSeq(ptr -> right);
    int size = left[0].size() + right[0].size() + 1;

    vector<bool> flags(left[0].size(), 0);
    for (int k = 0; k < right[0].size(); k++)
        flags.push_back(1);

    for (int i = 0; i < left.size(); i++) {
        for (int j = 0; j < right.size(); j++) {
            do {
                vector<int> tmp(size);
                tmp[0] = ptr -> val;
                int l = 0, r = 0;
                for (int k = 0; k < flags.size(); k++) {
                    tmp[k+1] = (flags[k]) ? right[j][r++] : left[i][l++];
                }
                results.push_back(tmp);
            } while (next_permutation(flags.begin(), flags.end()));
        }
    }

    return results;
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


int main(){
    /* Problem 4.9: BST Sequences: A binary search tree was created by traversing through an array from left to right and inserting each element. 
Given a binary search tree with distinct elements, print all possible arrays that could have led to this tree.
OJO A ESTE NO LE ENTENDÍ NADA  */
    vector<int> arr = {1,2,3,4,5,6};

    TreeNode* head = MinimalTree(arr, 0, arr.size() - 1);
    print2D(head);

}