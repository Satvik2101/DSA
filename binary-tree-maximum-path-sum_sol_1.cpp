#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
class Data{
    public:
    int leftSum;
    int rightSum;
    Data(int leftSum,int rightSum){
        this->leftSum = leftSum;
        this->rightSum = rightSum;
    }
};
class Solution {
public:
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
         helper(root);
        return ans;
    }
    
    int helper(TreeNode *root){
        if (root==NULL)return 0;
        int leftData = helper(root->left);
        int rightData = helper(root->right);
        // cout<<root->val<<" "<<leftData<<" "<<rightData<<endl;
        int maxChildData = max(leftData,rightData);
        if (leftData<=0 && rightData<=0){
            ans = max(ans,root->val);
            maxChildData = 0;
            return root->val;
        }
        else if (leftData+rightData+root->val > maxChildData){
            // cout<<leftData+rightData+root->val <<endl;
            ans = max(ans,leftData+rightData+root->val);
        }
        ans = max(ans,max(maxChildData,maxChildData+root->val));
        
        return maxChildData+root->val;
    }
    
    
};