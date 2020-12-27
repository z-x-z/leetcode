/// author: CagedBird
/// date: 2020/04/27
/// place: JiangXi
/// description: A code template of leetcode's list graph theory solution

#include<bits/stdc++.h>
#include<map>
#include<unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



class Solution {
public:
    Node* cloneGraphBFSHelper(Node* node)
    {
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[node] = new Node(node->val);
        queue<Node*> nodeQueue;
        nodeQueue.push(node);
        while (!nodeQueue.empty())
        {
            auto t = nodeQueue.front();
            nodeQueue.pop();
            Node* cloneNode = nodeMap[t];
            for (auto ptr: t->neighbors)
            {
                if(nodeMap.find(ptr)==nodeMap.end())
                {
                    nodeMap[ptr] = new Node(ptr->val);
                    nodeQueue.push(ptr);
                }
                cloneNode->neighbors.push_back(nodeMap[ptr]);
            } 
        }
        return nodeMap[node];
    }

    // 注意一定要深拷贝
    Node* cloneGraphDFSHelper(Node* node, unordered_map<int, Node*>& nodeMap) 
    {
        int val = node->val;
        if(nodeMap.find(val)!=nodeMap.end())
            return nodeMap[val];
        int size = node->neighbors.size();
        Node* clonedNode = new Node(val, vector<Node*>(size));
        nodeMap.insert(pair<int, Node* > {val, clonedNode});
        for (int i = 0; i < size; i++)
        {
            clonedNode->neighbors[i] = cloneGraphDFSHelper(node->neighbors[i], nodeMap);
        }
        return clonedNode;
    }
    Node* cloneGraph(Node* node) 
    {
        if(node==nullptr)
            return nullptr;
        unordered_map<int, Node*> nodeMap;
        return cloneGraphDFSHelper(node, nodeMap);
    }
};

int main()
{
    Solution aSolution;
    
}



