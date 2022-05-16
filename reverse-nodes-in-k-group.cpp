#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* check(ListNode* node, int k){
        while (k>1 && node!=NULL){
            node = node->next;
            k--;
        }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (check(head,k) == NULL) return head;
        
        ListNode* curLast = check(head,k);
        ListNode* prevHead = new ListNode(0);
        ListNode* headCopy = prevHead;

        while (curLast!=NULL){
            ListNode *nextNode = curLast->next;
            curLast->next = NULL;
            
            ListNode *prev = NULL;
            ListNode *curr = head;
            ListNode *nxt = curr->next;
            
            while (curr!=NULL){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            prevHead->next= prev;
            head->next= nextNode;
                        prevHead = head;

            head = nextNode;
            curLast = check(head,k);

        }
        return headCopy->next;
    }
};