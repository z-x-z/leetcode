/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's linkedList solution

#include<bits/stdc++.h>
using namespace std;

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
    static ListNode* init(int* array, int n)
    {
        ListNode* dump = new ListNode(-1);
        ListNode* p = dump;
        for (int i = 0; i < n; i++)
        {
            p->next = new ListNode(array[i]);
            p = p->next;
        }
        return dump->next;
    }
};

class Solution {
public:
    void reorderList(ListNode* head) 
    {
        ListNode* dumpHead = new ListNode(-1);
        dumpHead->next = head;
        int len = 0;
        ListNode* t = head;
        while(t)
        {
            t=t->next;
            len++;
        } 
        if(len<=2) return;
        ListNode* end =  reorderList(dumpHead, head, len-(len-1)/2);
        t = head;
        for (int i = 1; i < len; i++)
        {
            t = t->next;
        }
        t->next = NULL;
        
    }
    ListNode* reorderList(ListNode* dumpHead, ListNode* back, int left)
    {
        if(!back->next)
        {
            ListNode* t = dumpHead->next->next;
            dumpHead->next->next = back;
            back->next = t;
            return dumpHead->next->next;
        }
        ListNode* head = reorderList(dumpHead, back->next, left-1);
        if(left>0)
        {
            return NULL;
        } 
        ListNode* t = head->next->next;
        head->next->next = back;
        back->next = t;
        return head->next->next;
    }
    
};

int main()
{
    Solution aSolution;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 3; i <= 10; i++)
    {
        ListNode* head = new ListNode(array, i);
        aSolution.reorderList(head);    
        head->trave();
    }
}













