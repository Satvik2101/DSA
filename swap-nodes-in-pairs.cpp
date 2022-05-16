#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* headCopy = head;
        while (head!=NULL && head->next!=NULL){
            swap(head->val,head->next->val);
            head= head->next->next;
        }
        return headCopy;
    }
};