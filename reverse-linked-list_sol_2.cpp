#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/reverse-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL || head->next==NULL)return head;
        ListNode *curr = head;
        ListNode *fwd=  head->next;
        
        while (fwd!=NULL){
            ListNode *fwdNext = fwd->next;
            fwd->next = curr;
            curr=fwd;
            fwd=fwdNext;
        }
        head->next= NULL;
        return curr;
        
    }
};