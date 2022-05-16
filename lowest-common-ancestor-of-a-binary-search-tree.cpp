#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val){
            swap(p,q);
        }
        //p is smaller, q is larger
        while (root){
            if (root->val >= p->val && root->val <= q->val){
                return root;
            }
            if (root->val <= q->val){
                root = root->right;
            }else{
                root = root->left;
            }
            
        }
        return root;
    }
};