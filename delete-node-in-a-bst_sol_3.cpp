#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/delete-node-in-a-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* rootCopy = root;
        TreeNode *parent = NULL;
        while (root!=NULL && root->val != key ){
            parent = root;
            if (root->val < key) root = root->right;
            else root = root->left;
        }
        // cout<<root->val;
        if (root == NULL)return rootCopy;
        // bool isLeft = false;
        // if (parent->left == root) isLeft = true;
        if (!root->left || !root->right){
            TreeNode * newNode = root->left?root->left:root->right;
            delete root;
            if (parent==NULL){
                // cout<<"returning";
                return newNode;
            }
            
            if (root == parent->left) parent->left = newNode;
            else parent->right = newNode;
            return rootCopy;
       
        }else{
            TreeNode * toDeletePrev = NULL;
            TreeNode * toDelete = root->right;
            while (toDelete->left){
                toDeletePrev = toDelete;
                toDelete = toDelete ->left;
            }
            if (toDeletePrev == NULL){
                root->right = toDelete->right;
            }else{
                toDeletePrev->left = toDelete->right;
            }
            root->val = toDelete->val;
            delete toDelete;
        }
        return rootCopy;
    }
};