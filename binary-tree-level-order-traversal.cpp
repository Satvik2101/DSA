#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root==NULL)return {};
        vector<vector<int>> ans;
        vector<int> curr;
        ans.push_back({root->val});
        queue<TreeNode*> q;
        
        if (root->left)q.push(root->left);
        if (root->right)q.push(root->right);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();
            if (front==NULL){
                if (curr.size()>0)ans.push_back(curr);
                curr.clear();
                if (!q.empty()) q.push(NULL);
            }else{
                curr.push_back(front->val);
                if (front->left)q.push(front->left);
                if (front->right)q.push(front->right);
            }
        }
        return ans;
        
        
    }
};