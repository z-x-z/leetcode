#include <bits/stdc++.h>
using namespace std;
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
    int minDepth(TreeNode *root)
    {
        
        int depth = 0;
        if (!root)
            return depth;
        queue<TreeNode *> treeQueue;
        treeQueue.push(root);
        while (!treeQueue.empty())
        {
            depth++;
            int size = treeQueue.size();
            while(--size>=0)
            {
                TreeNode *node = treeQueue.front();
                treeQueue.pop();
                if (!node->left && !node->right)
                    return depth;
                if (node->left)
                    treeQueue.push(node->left);
                if (node->right)
                    treeQueue.push(node->right);
            }
        }
        return depth;
    }
};

int main()
{
    Solution aSolution;
    TreeNode *tree = new TreeNode(1);
    cout << "MinDepth: " << aSolution.minDepth(tree) << endl;
}