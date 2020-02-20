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
    ListNode* reverseList(ListNode* head) 
    {
        if(!head||!head->next) return head;
        ListNode* n = reverseList(head->next);
        n->next = head;
        head->next = NULL; // 使得最后一次递归头指针指向NULL
        return head;
    }
    void reverse(ListNode* p, ListNode* dumpHead)
    {
        if(!p) return ;
        reverse(p->next, dumpHead);
        dumpHead->next = p;
        // 绝对错误的操作!!!!
        // 在函数中对指针变量的赋值只能修改当前函数体中指针变量的指向
        // 而在其它地方，该指针仍然是指向调用之时的指向
        dumpHead = dumpHead->next;
    }
};

int main()
{
    Solution aSolution;
    int array[5] = {1, 2, 3, 4, 5};
    aSolution.reverseList(ListNode().init(array, 5))->trave();
}