#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/intersection-of-two-linked-lists

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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    while (headA!=NULL)
    {
        ListNode *headBCopy = headB;
        while (headBCopy!=NULL)
        {   if (headA ==headBCopy)
                return headA;
            headBCopy=headBCopy->next;
        }
        headA= headA->next;
    }
    return NULL;
}

};