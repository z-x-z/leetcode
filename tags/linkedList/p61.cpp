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
            printf(" %d", val);
            n = n->next;
        }
        printf("\n");
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL) return head;
        // 获取链表长度
        int len = 1;
        ListNode* p = head;
        while (p->next!=NULL)
        {
            p = p->next;
            len ++;
        }
        // p为链表的末节点
        if((k%=len)==0) return head;
        ListNode* tmp = head;
        for (int i = 0; i < len-k-1; i++)
        {
            tmp = tmp->next;
        }
        ListNode* newHead = tmp->next;
        tmp->next = NULL;
        p->next = head;
        return newHead;
    }
    
};

int main()
{
    Solution aSolution;
    
}