/// 张雄振
/// 2019/12/18
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    void trave()
    {
        printf("ListNode:");
        ListNode* n = next;
        while (n!=NULL)
        {
            printf(" %d", n->val);
            n = n->next;
        }
        printf("\n");
    }
};

class Solution {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* p = head;
        int len = 0;
        while(p)    
        {
            p = p->next;
            len++;
        }
        return fun(head, k, len);
    }
    ListNode* fun(ListNode* head, int k, int left)
    {
        if(left<k) return head;
        ListNode* p = head->next, * n;
        ListNode* t = head;
        for(int i=0;i<k-1;i++)
        {
            n = p->next;
            p->next = head;
            head = p;
            p = n;
        }
        t->next = fun(n, k, left-k);
        return head;
    }
};

int main()
{
    Solution aSolution;
    ListNode* l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);
    aSolution.reverseKGroup(l, 2)->trave();
}