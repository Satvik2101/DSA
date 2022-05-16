#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    unordered_map<int,int> m;
    int preIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0;i<inorder.size();i++){
            m.insert({inorder[i],i});
        }
        return helper(preorder,0,inorder.size()-1);
    }
    
    TreeNode* helper(vector<int>& pre, int l, int r){
        if (l>r) return NULL;
        int rootVal = pre[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        root->left = helper(pre,l,m[rootVal]-1);
        root->right = helper(pre,m[rootVal]+1,r);
        return root;
    }
};