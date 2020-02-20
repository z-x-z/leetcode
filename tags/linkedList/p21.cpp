/// 张雄振
/// 2019/12/18
#include<bits/stdc++.h>
using namespace std;
struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* dumpHead = new ListNode(-1);
        ListNode* p = dumpHead;
        while (l1!=NULL||l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                p->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                p->next = new ListNode(l2->val);
                l2 = l2->next;  
            } 
           p = p->next;
        }
        // 最后直接连接非空那一条指针
        if(l1!=NULL) p->next = l1;
        else p->next = l2;
        /* while (l1!=NULL)
        {
            p->next = new ListNode(l1->val);
            p = p->next;
            l1 = l1->next;  
        }
        while (l2!=NULL)
        {
            p->next = new ListNode(l2->val);
            p = p->next;
            l2 = l2->next;
        } 
        */
        return dumpHead;
    }
};

int main()
{
    Solution aSolution;
    int a= 1+1;
    a = 1<<1;
    a = 1/2;
    a = 1&&1;
    a = 1&1;
    a += 1;
}