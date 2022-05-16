#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        // if (root==NULL) return true;
        return helper(root,LONG_MAX,LONG_MIN);
    }
    //must be less than max, greater than min
    bool helper(TreeNode* root, long mx,long mn){
        if (root==NULL)return true;
        if ((root->val >= mx) || (root->val <= mn)){
            // cout<<root->val<<" "<<mx<<" "<<mn;
            return false;
        }
        return helper(root->left,root->val,mn) && helper (root->right,mx,root->val);
    }
};