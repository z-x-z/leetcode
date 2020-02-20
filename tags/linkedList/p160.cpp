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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* p1 = headA, * p2 = headB;
        int count = 0;
        // p1 p2 指针在各自的第二次循环中若有交点则必相交
        /* 
            设headA 长度为l1，交点在其i1处
            设headB 长度为l2，交点在其i2处
            则当p1遍历完l1后继续遍历l2并到达headB的交点处时，p1走过l1+i2步
            此时p2也走过l1+i2步，即此时p2处于headA的l1-l2+i2处
            又因为有：l1-i1 = l2-i2 -> l1-l2 = i1-i2
            即此时p2正处于p1的i1处，即此时两者皆处于交点处

        */
        while (true)
        {
            if(headA==headB) return headA;
            p1 = p1->next;
            if(!p1)
            {
                count++;
                if(count>=3) break;
                p1 = headB;
            }
            p2 = p2->next;
            if(!p2)
            {
                count++;
                if(count>=3) break;
                p2 = headA;
            }
        }
        return NULL;
    }
    
    
};

int main()
{
    Solution aSolution;
    
}













