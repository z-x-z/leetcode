/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's linkedList solution

#include<bits/stdc++.h>

// ListNode Implemention
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int* array, int n)
    {
        ListNode* head = this;
        if(n==0) return;
        head->val = array[0];
        for (int i = 1; i < n; i++)
        {
            head->next = new ListNode(array[i]);
            head = head->next;
        }
    }
    void trave()
    {
        printf("ListNode:");
        ListNode* p = this;
        while (p!=NULL)
        {
            printf(" %d", p->val);
            p = p->next;
        }
        printf("\n");
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* dumpSamell = new ListNode(-1), * ps = dumpSamell;    
        ListNode* dumpNotSamell = new ListNode(-1),* pn = dumpNotSamell;
        while (head)
        {
            ListNode* n = head->next;
            if(head->val<x) 
            {
                dumpSamell->next = head;
                dumpSamell = head;
            }
            else
            {
                dumpNotSamell->next = head;
                dumpNotSamell = head;
            }
            head = n;
        }
        // 尾指针设为NULL
        dumpNotSamell->next = NULL;
        // 头尾相接
        dumpSamell->next = pn->next;
        return ps->next;
    }
    
};

int main()
{
    Solution aSolution;
    const int n = 6;
    int arr[n]={1, 4, 3, 2, 5, 2};
    aSolution.partition(new ListNode(arr, n), 3)->trave();
}













