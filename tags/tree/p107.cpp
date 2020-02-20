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
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        while(!treeQueue.empty())
        {
            queue<TreeNode*> swapQueue;
            vector<int> vec;
            while (!treeQueue.empty())
            {
                TreeNode* node = treeQueue.front();
                vec.push_back(node->val);
                if(node->left) swapQueue.push(node->left);
                if(node->right) swapQueue.push(node->right);
            }
            result.push_back(vec);
            treeQueue = swapQueue;
        }
        // 使用algorihtm的reverse函数
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution aSolution;
    cout<<"a"; 
}