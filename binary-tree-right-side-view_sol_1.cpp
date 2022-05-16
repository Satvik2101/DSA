#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        if (root==NULL)return{};
        vector<int> ans;
        vector<int> curr;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if (front == NULL){
                ans.push_back(curr.back());
                curr.clear();
                if (!q.empty())
                q.push(NULL);
            }else{
                curr.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right)q.push(front->right);
            }
        }
        return ans;
    }
};