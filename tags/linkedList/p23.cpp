/// 张雄振
/// 2019/12/18
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    public:
    ListNode(int x) : val(x), next(NULL) {}
   
    ListNode(const vector<int>& vals) // 需要加const，否则无法利用此初始化
    {
        int len = vals.size();
        if(len>0) val = vals[0];
        ListNode* p = this;
        for (int i = 1; i < len; i++)
        {
            p->next = new ListNode(vals[i]);
            p = p->next;
        }
        
    }
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

struct node
{
    int val;
    int index;
    node(int _val, int _index): val(_val), index(_index){}
    bool operator >(const node& n) const // grater需要重载>
    {
        return val>n.val;
    }
};


class Solution {
public:
    /* way1 直接法
        int k = lists.size();
        vector<int> vals;
        for (int i = 0; i < k; i++)
        {
            ListNode* h = lists[i];
            while(h!=NULL) 
            {
                vals.push_back(h->val);
                h = h->next;
            }
        }
        sort(vals.begin(), vals.end());
        ListNode* dumpHead = new ListNode(-1);
        ListNode* p = dumpHead;
        for(int i = 0, len = vals.size();i<len;i++)
        {
            p->next = new ListNode(vals[i]);
            p = p->next;
        }
        return dumpHead->next; 
        */

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // 优先队列法
        int k = lists.size();   
        ListNode* dumpHead = new ListNode(-1);
        ListNode* p = dumpHead;
        priority_queue<node, vector<node>, greater<node> > pQueue; 
        for (int i = 0; i < k; i++)
        {
            if(lists[i]!=NULL) pQueue.push(node(lists[i]->val, i));
        }
        while(!pQueue.empty())
        {
            p->next = new ListNode(pQueue.top().val);
            p = p->next;
            int index = pQueue.top().index;
            pQueue.pop();
            lists[index] = lists[index]->next;
            if(lists[index]!=NULL) pQueue.push(node(lists[index]->val, index));
        }
            
        return dumpHead->next;
    }
};

int main()
{
    Solution aSolution;
    vector<ListNode*> lists;
    lists.push_back(new ListNode(vector<int> {1, 4, 5}));
    lists.push_back(new ListNode(vector<int> {1, 3, 4}));
    lists.push_back(new ListNode(vector<int> {2, 6}));
    ListNode* p = aSolution.mergeKLists(lists);
    p->trave();
}