#include<iostream>
#include<vector>
#include"Binary_tree.cpp";
using namespace std;
vector<int> *op=new vector<int>();
void helper(Node * root){
    if(root==NULL){
        return;

    }

    helper(root->left);
    op->push_back(root->data);
    helper(root->right);
}

int KthSmallestElement(Node *root, int k)
{
    helper(root);

    return op->at(k-1);

}
// Time complexity O(N) and SPACE Complexity O(N)....
//====================================================================================
// Function to find k'th largest element in BST
// Here count denotes the number of nodes processed so far
int kthSmallest(Node* root, int& k)
{
    // base case
    if (root == NULL)
        return -1;

    // search in left subtree
    int left = kthSmallest(root->left, k);

    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;

    // if current element is k'th smallest, return it
    k--;
    if (k == 0)
        return root->data;

    // else search in right subtree
    return kthSmallest(root->right, k);
}
// Time complexity O(N) and SPACE Complexity O(1)....
