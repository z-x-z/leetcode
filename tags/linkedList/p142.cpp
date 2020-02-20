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
// 设链表中非环形部分的长度为F，环形部分长度为N
// 设slow与fast最终经过F+a步相遇
// 设slow继续走需要b步到达环形起点，则b = F - a
// Therefore:
//          2 * (F + a) = F + a + K * N, K = 1, 2, 3 ...
//                  F = b + K0*N, b = F - a, K0 = 0, 1, 2 ...
// 所以此时若一指针从头出发到达环形起点需要F步，则此时slow指针也已经走过b + K0*N，即此时slow指针也达到环形起点
// 故两者保持前进必定在环形起点第一次相遇
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        // 慢指针一次走一步，快指针一次走两步，故在环形区域两者一定会相遇
        int totalLen = 0;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            totalLen++;
            if(slow==fast) break;
        }
        if(!fast) return NULL;
        while(head!=slow)
        {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
    
};

int main()
{
    Solution aSolution;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = l1->next->next;
    ListNode* l = aSolution.detectCycle(l1);
    if(l) std::cout<<l->val;
}













