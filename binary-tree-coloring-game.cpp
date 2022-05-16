#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/binary-tree-coloring-game

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
    TreeNode * xNode;
    int x;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        this->x = x;
        int parentCount;
        int leftCount;
        int rightCount;
        int totalCount;
        totalCount = count(root);
        leftCount = count(xNode->left);
        rightCount = count(xNode->right);
        parentCount = totalCount -leftCount-rightCount-1;
        
        int maxVal = max(leftCount,max(rightCount,parentCount));
        int minVal = min(leftCount,min(rightCount,parentCount));
        int midVal = parentCount+leftCount+rightCount-maxVal-minVal;
        
        if (maxVal>minVal+midVal)return true;
        return false;
        
    }
    
    int count(TreeNode* root){
        int ans = 0;
        if (root==NULL) return ans;
        ans += count(root->left);
        ans += count(root->right);
        if (root->val == x) xNode = root;
        return ans+1;
    }
};