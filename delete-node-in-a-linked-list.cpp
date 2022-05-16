#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/delete-node-in-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next->next!=NULL)
        {   
            node->val=node->next->val;
            node=node->next;
            
        }
        node->val = node->next->val;
        node->next=NULL;
        
        delete(node->next);
        
    }
};