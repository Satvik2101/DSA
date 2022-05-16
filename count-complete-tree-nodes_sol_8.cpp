#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/count-complete-tree-nodes

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
    int countNodes(TreeNode* root) {
        if (root==NULL)return 0;
        int leftHeight=0;
        int rightHeight=0;
        
        TreeNode *left = root;
        TreeNode *right = root;
        while (left){
            left = left->left;
            leftHeight++;
        }
        while (right){
            right = right->right;
            rightHeight++;
        }
        if (leftHeight == rightHeight) return pow(2,leftHeight)-1;
        
        return countNodes(root->left)+countNodes(root->right)+1;
        
//         if(!root) return 0;

//         int hl=0, hr=0;

//         TreeNode *l=root, *r=root;

//         while(l) {hl++;l=l->left;}

//         while(r) {hr++;r=r->right;}

//         if(hl==hr) return pow(2,hl)-1;

//         return 1+countNodes(root->left)+countNodes(root->right);
    }
};