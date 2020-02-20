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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dumpHead = new ListNode(-1);
        ListNode* p = dumpHead;
        ListNode* l, * r;
        while (head!=NULL)
        {
            l = head;
            r = l->next;
            while (r!=NULL&&r->val==l->val)
            {
                r = r->next;
            }
            head = r->next;
        }
        return dumpHead->next;
    }
};

int main()
{
    Solution aSolution;
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(2);
    aSolution.deleteDuplicates(p)->trave();
    
}