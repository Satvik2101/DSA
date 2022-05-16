#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

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
    int ans;
public:
    int longestZigZag(TreeNode* root) {
        ans = 0;
        traverse(root,0,false);
        traverse(root,0,true);
        return ans;
    }
    
    void traverse(TreeNode* root, int count,bool isLeft){
        ans = max(ans,count);
        if (root->right){
            traverse(root->right,isLeft?count+1:1,false);
        }
        if (root->left){
            traverse(root->left,isLeft?1:count+1,true);
        }
    }
};