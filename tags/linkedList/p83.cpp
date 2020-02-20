/// 张雄振
/// 2019/12/18
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    void trave()
    {
        printf("ListNode:");
        ListNode* n = next;
        while (n!=NULL)
        {
            printf(" %d", n->val);
            n = n->next;
        }
        printf("\n");
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        // 可以直接在原链表中删除重复的数据
        ListNode* copy = head;
        while (head!=NULL)
        {
            int val = head->val;
            ListNode* p = head->next;
            while(p!=NULL&&p->val==val)
            {
                ListNode* t= p;
                p = p->next;
                delete t;
            }
            head->next = p;
            head = head->next;
        }
        return copy;
    }
    
};

int main()
{
    Solution aSolution;
    ListNode* p = new ListNode(1);
    p->next = new ListNode(1);
    p->next->next = new ListNode(2);
    aSolution.deleteDuplicates(p)->trave();
    
}