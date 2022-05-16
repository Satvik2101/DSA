#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/binary-tree-cameras

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
    int ans=0;
    unordered_set<TreeNode*> areCovered;
    
    bool contains(TreeNode* node){
        return areCovered.find(node) !=areCovered.end();    
    }
    int minCameraCover(TreeNode* root) {
        areCovered.insert(NULL);
        dfs(root,NULL);
        return ans;
    }
    
    void dfs(TreeNode* curr, TreeNode* parent){
        if (curr!= NULL){
            dfs(curr->left,curr);
            dfs(curr->right,curr);
        
            if ((parent==NULL && !contains(curr)) || !contains(curr->left) || !contains(curr->right)){
                ans++;
                areCovered.insert(curr);
                areCovered.insert(parent);
                areCovered.insert(curr->left);
                areCovered.insert(curr->right);

            }
        }
    }
};