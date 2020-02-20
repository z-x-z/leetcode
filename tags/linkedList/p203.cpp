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
    ListNode(int* array, int n)
    {
        ListNode* head = this;
        if(n==0) return;
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
        ListNode* p = this;
        while (p!=NULL)
        {
            printf(" %d", p->val);
            p = p->next;
        }
        printf("\n");
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dumphead = new ListNode(-1);
        dumphead->next = head;
        head = dumphead;
        while (head&&head->next)
        {
            if(head->next->val==val) head->next = head->next->next;
            // 注意此时若删除了节点则p就不需要再向后遍历
            else head = head->next;
        }
        return dumphead->next;
    }
    
};

int main()
{
    Solution aSolution;
    int arr[8] = {6, 3, 4 ,6, 6, 7 ,1, 6};
    aSolution.removeElements(new ListNode(arr, 8), 6)->trave();
}













