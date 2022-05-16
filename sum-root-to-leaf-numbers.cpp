#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    int finalAns = 0;
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return finalAns;
    }
    void helper(TreeNode *root, int parentVal){
        if (root==NULL) return;
        int thisVal = parentVal*10 + root->val;
        if ((!root->left) && (!root->right)){
            //leaf node;
            finalAns += thisVal;
            return;
        }
        // cout<<root->val<<" "<<thisVal<<endl;
        helper(root->left,thisVal);
        helper(root->right,thisVal);
    }
};