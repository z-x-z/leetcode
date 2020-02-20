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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* dumpHead = new ListNode(-1);
        ListNode* p = dumpHead;
        while (l1!=NULL&&l2!=NULL)
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
        if(l1!=NULL) p->next = l1;
        else p->next = l2;
        return dumpHead->next;
    }
    // 分治法解决
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n = lists.size();
        while(n>1)
        {
            for (int j = 0; j < n/2; j++)
            {
                lists[j] = mergeTwoLists(lists[2*j], lists[2*j+1]);
            }
            if(n%2==1) lists[n/2+1] = lists[n-1];
            n/=2;
        }
        return lists[0];
    }
};

int main()
{
    Solution aSolution;
    
}