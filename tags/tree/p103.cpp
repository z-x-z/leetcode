/// author: CagedBird
/// date: 2020/1/5
/// place: BeiJing
/// description: A code template of leetcode's tree solution
#include<bits/stdc++.h>
using namespace std;

// Binary TreeNode Implemention
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     void trave()
     {
         printf("Tree level order: ");
         queue<TreeNode*> treeQueue;
         treeQueue.push(this);
         while (!treeQueue.empty())
         {
            auto node = treeQueue.front();
            treeQueue.pop();
            printf("%d ", node->val);
            if(node->left) treeQueue.push(node->left);
            if(node->right) treeQueue.push(node->right);
         }
     }
};

class Solution {
public:
    // 双向队列
    vector<vector<int> > zigzagLevelOrder1(TreeNode* root)
    {
        vector<vector<int> > vec;
        if(!root) return vec;
        queue<TreeNode*> treeQueue; treeQueue.push(root);
        int level=0;
        while (!treeQueue.empty())
        {
            int n = treeQueue.size();
            deque<int> intDeque;
            for(int i =0;i<n;i++)
            {
                TreeNode* node = treeQueue.front();
                treeQueue.pop();
                // 利用双向队列的插入顺序不一样使得实现锯齿遍历
                if(level%2==0) intDeque.push_back(node->val);
                else intDeque.push_front(node->val);
                if(node->left) treeQueue.push(node->left);
                if(node->right) treeQueue.push(node->right);
            }   
            // 这里使用了容器的初始化
            vec.push_back(vector<int>(intDeque.begin(), intDeque.end()));
            level++;
        }
        return vec;
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int> > vec;
        if(!root) return vec;
        stack<pair<TreeNode*, int> > even;
        stack<pair<TreeNode*, int> > odd;
        int level = 0;
        even.push(make_pair(root, 0));
        while (even.size()!=0||odd.size()!=0)
        {
            vector<int> tmp;
            // 遍历实际上全为后进先出
            if(level%2==0)
                while (!even.empty())
                {
                    auto node = even.top().first; even.pop();
                    tmp.push_back(node->val);
                    if(node->left) odd.push(make_pair(node->left, level+1));
                    if(node->right) odd.push(make_pair(node->right, level+1));
                }
            else 
                while (!odd.empty())
                {
                    auto node = odd.top().first; odd.pop();
                    tmp.push_back(node->val);
                    if(node->right) even.push(make_pair(node->right, level+1));
                    if(node->left) even.push(make_pair(node->left, level+1));
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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    aSolution.zigzagLevelOrder(root);
}