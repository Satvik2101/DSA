#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    TreeNode * rightMost(TreeNode *root){
        while (root !=NULL && root->right!=NULL){
            root = root->right;
            cout<<root->val<<" ";
        }
        
        return root;
    }
    void flatten(TreeNode* root) {
        while (root){
            if (!(root->left)){
                root = root->right;
                continue;
            }
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            // cout<<root->val<<" ";
            TreeNode* insertAt = rightMost(root);
            insertAt->right = temp;
            root = root->right;
        }
    }
};