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
    //  只给了要被删除的节点
    //  巧妙的O(1)方法
    void deleteNode(ListNode* node) 
    {
        // 将下一个值拷贝过来
        node->val = node->next->val;
        ListNode* tmp = node->next;
        // 链表接下去
        node->next = node->next->next;
        // 防止内存泄漏
        delete tmp;
    }
    
};

int main()
{
    Solution aSolution;
    
}













