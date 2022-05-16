#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root,Node *sibling = NULL) {
        if (root==NULL || root->left ==NULL)return root;
        root->left->next = root->right;
        if (sibling!=NULL)
        root->right->next = sibling->left;
        connect(root->left,root->right);
        connect(root->right,sibling==NULL?NULL:sibling->left);
        return root;
    }
};