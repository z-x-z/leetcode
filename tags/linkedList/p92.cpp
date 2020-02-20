/// 张雄振
/// 2019/12/18
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int x) : val(x), next(NULL) {}
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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        ListNode* dumpHead= new ListNode(-1);
        ListNode* p = dumpHead;
        ListNode* pre = head;
        for (int i = 1; i < m; i++)
        {
            dumpHead->next = head;
            pre = head;
            dumpHead = dumpHead->next;
            head = head->next;
        }
        ListNode* t = head;
        ListNode* left = head;
        head = head->next;
        ListNode* right= NULL;
        for (int i = m; i < n; i++)
        {
            right = head->next;
            head->next = left;
            left = head;
            head = right;
        }
        if(m==1)
        {
            pre->next = head;
            return left;
        } 
        pre->next = left;
        t->next = right;
        return p->next;
    }

};

int main()
{
    Solution aSolution;
    int array[7]={1, 2, 3, 4, 5, 6, 7};
    aSolution.reverseBetween(ListNode().init(array, 7), 1, 7)->trave();
}