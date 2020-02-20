#include<iostream>
using namespace std;
struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
      void traverse()
      {
          printf("%d", this->val);
          ListNode* p = next;
          while(p!=NULL)
          {
            printf("->%d", p->val);
            p = p->next;
          }
      }
};

class Solution 
{
    public:
    // 1->2->3->4->5->NULL
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dumbPointer = new ListNode(0);
        dumbPointer->next = head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i = 0; i < n; i++)
        {
            p1 = p1->next;
        }
        if(p1==NULL) return dumbPointer->next->next;
        while(p1->next!=NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return dumbPointer->next;
    }
};

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    Solution solution;
    ListNode* h = solution.removeNthFromEnd(l1, 2);
    h->traverse();
    return 0;
}