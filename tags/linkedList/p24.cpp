/// 张雄振
/// 2019/12/18
#include <bits/stdc++.h>
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
            printf(" %d", val);
            n = n->next;
        }
        printf("\n");
    }
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        /* non-recursive
        ListNode* dumpHead = new ListNode(0);
        dumpHead->next = head;
        ListNode* tmp = dumpHead;
        while(tmp->next!=NULL&&tmp->next->next!=NULL)
        {
            ListNode* l = tmp->next;
            ListNode* r = tmp->next->next;
            l->next = r->next;
            tmp->next = r;
            r->next = l;
            tmp = l;
        }
        return dumpHead->next; 
        */
        if (head != NULL&&head->next!=NULL)
        {
            /*  recursive way2 
            ListNode* nextP = head->next;
            head->next = swapPairs(nextP->next);
            nextP->next = head;
            return nextP; 
            */

            // recursive way1
            ListNode *tmp = head->next->next;
            head->next->next = head;
            ListNode* curHead = head->next;
            head->next = swapPairs(tmp);
            return curHead; 
           
        }
        else
            return head;
    }
};

int main()
{
    Solution aSolution;
    ListNode* l1= new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    aSolution.swapPairs(l1);
}