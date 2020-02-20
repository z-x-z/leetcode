/// author: CagedBird
/// date: 2020/1/5
/// place: BeiJing
/// description: A code template of leetcode's tree solution
#include <bits/stdc++.h>
using namespace std;

// Binary TreeNode Implemention
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // 递归法
    vector<vector<int> > levelNodes;
    vector<vector<int> > levelOrder_recur(TreeNode *root)
    {
        if(root) build(root, 0);
        return levelNodes;
    }
    // BFS遍历
    void build(TreeNode *node, int level)
    {
        // 最先遍历每一层的最左边时先创建vector<int>
        if(levelNodes.size()==level) levelNodes.push_back(vector<int>());
        levelNodes[level].push_back(node->val);
        if(node->left) build(node->left, level+1);
        if(node->right) build(node->right, level+1);
    }
    
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > vec;
        if(!root) return vec;
        queue<pair<TreeNode*, int> > treeQueue;
        int level = 0;
        treeQueue.push(make_pair(root, level));
        while (!treeQueue.empty())
        {
            vector<int> tmp;
            while (treeQueue.front().second==level)
            {
                auto node = treeQueue.front().first;
                treeQueue.pop();
                tmp.push_back(node->val);
                if(node->left) treeQueue.push(make_pair(node->left, level+1));
                if(node->right) treeQueue.push(make_pair(node->right, level+1));
            }
            if(tmp.size()!=0) vec.push_back(tmp);
            level++;
        }
        return vec;
    }
};

int main()
{
    Solution aSolution;
}