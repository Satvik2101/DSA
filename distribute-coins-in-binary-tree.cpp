#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/distribute-coins-in-binary-tree

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
    int ans;
    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode *node){
        if (!node)return 0;
        int leftAns = dfs(node->left);
        int rightAns = dfs(node->right);
        ans += abs(leftAns)+abs(rightAns);
        return node->val +leftAns+rightAns-1;
    }
};