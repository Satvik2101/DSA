#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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

class NodeData{
    public:
    int parentSum;
    int leftSum;
    int rightSum;
    int val;
};
class Solution {
    long long total=0; long long ans = 0;
public:
    int INF = 1e9+7;
    int maxProduct(TreeNode* root) {
        total = helper(root);
        helper(root);
        return ans%INF;
    }
    
    int helper(TreeNode * root){
        if (!root) return 0;
        int sum = helper(root->left)+helper(root->right)+root->val;
        if (total!=0) ans = max(ans, sum * (total-sum));
        return sum;
    }   
};