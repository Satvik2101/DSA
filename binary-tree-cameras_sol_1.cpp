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
    enum Cam{
        covered,contains,needs
    };
public:
    int ans;
    int minCameraCover(TreeNode* root) {
        ans = 0;
        Cam rootAns = dfs(root);
        if(rootAns == needs)ans++;
        return ans;
    }
    
    Cam dfs(TreeNode *node){
        if (!node) return covered;
        
        Cam left = dfs(node->left);
        Cam right = dfs(node->right);
        
        if (left==needs || right == needs){
            ans++;
            return contains;
        }
        if (left == contains || right == contains){
            return covered;
        }
        return needs;
    }
};