#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    int val;
    int height;
    
    bool operator < (const NodeData &other)const{
        if (height==other.height) return val<other.val;
        return height<other.height;
    }
    NodeData(int val,int height){
        this->val = val;
        this->height = height;
    }
};
class Solution {
public:
    //offset - [(height,val)]
    map<int,multiset<NodeData>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root==NULL)return{};  
        helper(root,0,0);
        vector<vector<int>> ans;
        for (auto s:m){
            vector<int> curr = {};
            for (NodeData data:s.second){
                curr.push_back(data.val);
            }
            ans.push_back(curr);
        }
        return ans;
    }
    void helper(TreeNode* root, int height, int offset){
        if (root==NULL) return;
        m[offset].insert(NodeData(root->val,height));
        if (root->left) helper(root->left,height+1,offset-1);
        if (root->right) helper(root->right,height+1,offset+1);
    }
};