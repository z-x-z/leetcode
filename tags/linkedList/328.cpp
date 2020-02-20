/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's linkedList solution

#include <bits/stdc++.h>

// ListNode Implemention
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int *array, int n)
    {
        ListNode *head = this;
        if (n == 0)
            return;
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
        ListNode *p = this;
        while (p != NULL)
        {
            printf(" %d", p->val);
            p = p->next;
        }
        printf("\n");
    }
};

class Solution
{
public:
    //奇偶混排
    ListNode *oddEvenList(ListNode *head)
    {
        // 0, 1, 2个节点不用排
        if (!head || !head->next || !head->next->next)
            return head;
        // 头节点视为奇节点
        ListNode *odd = new ListNode(-1), *oddp = odd;
        odd->next = head;
        odd = odd->next;
        // 一定存在偶节点
        ListNode *even = new ListNode(-2), *evenp = even;
        even->next = head->next;
        even = even->next;
        // 奇节点数一定不少于偶节点数
        while (even&&even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        if(even) even->next = NULL;
        odd->next = evenp->next;
        return oddp->next;
    }
};

int main()
{
    Solution aSolution;
    int arr[]={1, 2, 3, 4, 5, 6};
    aSolution.oddEvenList(new ListNode(arr, 6))->trave();
}
