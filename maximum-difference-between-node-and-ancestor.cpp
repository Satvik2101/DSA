#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

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
    
    int maxAncestorDiff(TreeNode* root) {
        pair<int,int> finalAns = maxMin(root);
         ans = max(ans, max(abs(root->val-finalAns.first),abs(root->val-finalAns.second)));
        return ans;
    }
    
    pair<int,int> maxMin(TreeNode* root){
        if (root->left==NULL && root->right == NULL){
            return make_pair(root->val,root->val);
        }
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        pair<int,int> finalAns;
        if (root->right ==NULL){
            finalAns= maxMin(root->left);
        }
        else if (root->left ==NULL){
            finalAns= maxMin(root->right);
        }
        else{
            pair<int,int> p1 = maxMin(root->left);
            pair<int,int> p2 = maxMin(root->right);
            
            minVal = min(p1.first,p2.first);
            maxVal = max(p1.second,p2.second);
            
            finalAns = make_pair(minVal,maxVal);
        }
        ans = max(ans, max(abs(root->val-finalAns.first),abs(root->val-finalAns.second)));
        minVal = min(finalAns.first,root->val);
        maxVal = max(finalAns.second,root->val);
        finalAns = make_pair(minVal,maxVal);
        return finalAns;
    }
};