/// author: CagedBird
/// date: 2019/06/26
/// place: JiangXi
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
    static ListNode* init(const vector<int>& array)
    {
        ListNode*  dumpHead = new ListNode(-1);
        ListNode* copyHead = dumpHead;
        for (int i = 0; i < array.size(); i++, dumpHead = dumpHead->next)
            dumpHead->next = new ListNode(array[i]);
        return copyHead->next;
    }
    void trave()
    {
        printf("ListNode:");
        ListNode* p = this;
        while (p)
        {
            printf(" %d", p->val);
            p = p->next;
        }
        printf("\n");
    }
};

class Solution {
public:
    /// 面试题 02.01. 移除重复节点
    ListNode* removeDuplicateNodes(ListNode* head)
    {
        unordered_set<int> valSet;
        ListNode* pre = new ListNode(-1), * node;
        node = head;
        pre->next = head;
        while(node)
        {
            if(valSet.count(node->val))
                pre->next = node->next;
            else
            {
                pre = pre->next;
                valSet.insert(node->val);
            }
            node = node->next;
        }
        return head;
    }

};

int main()
{
    Solution aSolution;
    vector<int> arr{1, 2, 3, 2, 1, 4};
    ListNode* head =  ListNode::init(arr);
    aSolution.removeDuplicateNodes(head)->trave();
}













