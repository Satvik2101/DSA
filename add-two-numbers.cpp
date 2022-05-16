#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/add-two-numbers

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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* headCopy = head;
        int adder = 0;
        ListNode *prev;
        while (l1!=NULL || l2!=NULL){
            
            int val1 = l1==NULL?0:l1->val;
            int val2 = l2==NULL?0:l2->val;
            int currentValue = val1+val2 + adder;
            adder = currentValue/10;
            currentValue = currentValue%10;
            head->val = currentValue;
            head->next = new ListNode();
            prev = head;
            head=head->next;
            if (l1!=NULL)
                l1=l1->next;
            if (l2!=NULL)
                l2=l2->next;
        }
        if (adder!=0){
            prev->next = new ListNode(adder);
        }       
        else{
            prev->next = NULL;
        }
        return headCopy;
    }
};