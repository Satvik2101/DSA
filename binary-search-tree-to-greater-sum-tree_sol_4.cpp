#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

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
    TreeNode* bstToGst(TreeNode* root) {
        gstHelper(root,0);
        return root;
    }
    
    int gstHelper(TreeNode* root, int baseSum){
        int rightSum;
        if (root->right) rightSum = gstHelper(root->right,baseSum);
        else rightSum = baseSum;
        root->val = rightSum + root->val;;
        
        if (root->left){
            return gstHelper(root->left,root->val);
        }else return root->val;
    }
};