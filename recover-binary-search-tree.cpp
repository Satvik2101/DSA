#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/recover-binary-search-tree

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
    void recoverTree(TreeNode* root) {
        // Morris traversal
        
        TreeNode * temp = NULL;
        TreeNode * pre, *first,*second;
        pre = first = second = NULL;
        while (root){
            if (root->left){
                temp = root->left;
                
                while (temp->right!= NULL && temp->right!=root){
                    temp = temp->right;
                }
                if (temp->right != NULL){
                    //threading already exists, do work
                    if (pre!= NULL && pre->val > root->val){
                        if (!first) first = pre;
                        second = root;
                    }
                    pre = root;
                    temp->right = NULL;
                    root=root->right;
                }else{
                    // create threading
                    temp->right = root;
                    root = root->left;
                }
            }else{
                // do work
                if (pre!= NULL && pre->val > root->val){
                        if (!first) first = pre;
                        second = root;
                    }
                pre = root;
                root = root->right;
            }
        }
        if (first != NULL && second!= NULL){
            swap(first->val,second->val);
        }
    }
};