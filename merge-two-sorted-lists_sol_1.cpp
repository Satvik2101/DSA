#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/merge-two-sorted-lists

void append(ListNode *head, int i)
{
    ListNode *newNode = new ListNode();
    newNode->val = i;
    newNode->next = NULL;
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1==NULL)return l2;
        else if (l2==NULL)return l1;
        else if (l1==NULL && l2 == NULL)return NULL;
        ListNode *newList = new ListNode();
        newList->next = NULL;
        if (l1->val > l2->val)
            {
                newList->val=l2->val;
                l2 = l2->next;
            }
            else
            {
                newList->val=l1->val;
                l1 = l1->next;
            }
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val > l2->val)
            {
                append(newList, l2->val);
                l2 = l2->next;
            }
            else
            {
                append(newList, l1->val);
                l1 = l1->next;
            }
        }
        if (l2==NULL)
        {
            while(l1!=NULL)
            {
                append(newList,l1->val);
                l1=l1->next;
            }
        }
        else
        {
            while(l2!=NULL)
            {
                append(newList,l2->val);
                l2=l2->next;
            }
        }
        return newList;
    }
};
void printList(ListNode *n)
{
    while (n != NULL)
    {
        cout << n->val << endl;
        n = n->next;
    }
}