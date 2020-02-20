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
    bool hasCycle(ListNode *head) 
    {
        if(!head) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        // 慢指针一次走一步，快指针一次走两步，故在环形区域两者一定会相遇
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

int main()
{
    Solution aSolution;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = l1;
    cout<<aSolution.hasCycle(l1)<<endl;
}