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
    bool isPalindrome(ListNode* head) 
    {
        // 快慢指针法，快指针每次走两步，慢指针每次走1步并反转
        if(!head||!head->next) return true;
        ListNode* fast, * slow,* tmp, *pre;
        fast = slow = head;
        pre = slow->next;
        while (fast->next&&fast->next->next)
        {
            fast = fast->next->next;
            tmp = slow;
            slow = pre;
            pre = slow->next;
            slow->next = tmp;
        }
        // if(fast==slow)
        // {
        //     // n = 2
        //     return head->val==head->next->val;
        // }
        if(!fast->next) slow = slow->next;
        fast = pre;
        while(fast)
        {
            if(fast->val!=slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }  
};

int main()
{
    Solution aSolution;
    int arr[6] = {1, 2, 2, 1, 23, 1};
    ListNode* l = new ListNode(arr, 4);
    std::cout<<aSolution.isPalindrome(l);
}













