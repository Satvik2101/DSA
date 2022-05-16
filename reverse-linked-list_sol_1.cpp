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
        if (head == NULL) return NULL;
        ListNode* revList = new ListNode(head->val);//end of reversed list
        ListNode *prev = revList;
        while (head->next!=NULL)
        {
            head = head ->next;
            ListNode* newNode = new ListNode(head->val,prev);
            prev = newNode;
        }
        return prev;
    }
};