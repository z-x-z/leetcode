/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's linkedList solution

#include<bits/stdc++.h>
using namespace std;

// ListNode Implemention
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        return copyList(head, unordered_map<Node*, Node*> nodeSet());
    }
    Node* copyList(Node* head, unordered_set<Node*, Node*>& nodeSet)
    {
        if(!head) return NULL;
        if(nodeSet.find(head)!=nodeSet.end()) return nodeSet[head];
        Node* node = new Node(head->val);
        nodeSet[head] = node;
        node->next = copyList(head->next, nodeSet);
        node->random = copyList(head->random);
        return node;
    }
};

int main()
{
    Solution aSolution;
    
}













