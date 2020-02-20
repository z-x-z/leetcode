/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's linkedList solution

#include<bits/stdc++.h>
using namespace std;

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

class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        int n= 0;
        while(head) 
        {
            head = head->next;
            n++;
        }
        int half = n/2;
        ListNode* right = head;
        for(int i = 0;i<half;i++) right = right->next;
        return megerSort(head, right, half)
    }
    ListNode* megerSort(ListNode* left, ListNode* right, int half)
    {
        if(half==1) 
        {

        }
        unordered_set
        
    }
    
};

int main()
{
    Solution aSolution;
    
}













