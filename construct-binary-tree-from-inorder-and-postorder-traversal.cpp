#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    int postIndex;
    unordered_map<int,int> m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size()-1;
        for (int i = 0;i<inorder.size();i++){
            m.insert({inorder[i],i});
        }
        return helper(postorder,0,postorder.size()-1);
    }
    TreeNode *helper(vector<int>& post,int l, int r){
        if (l>r) return NULL;
        if (postIndex<0) return NULL;
        TreeNode *root = new TreeNode(post[postIndex--]);
        cout<<root->val<<" ";
        root->right = helper(post,m[root->val]+1,r);
        root->left = helper(post,l,m[root->val]-1);
       
        // cout<<root->val<<" ";
        // if (root->left) cout<<root->left->val<<endl;
        // else cout<<endl;

        return root;
    }
};