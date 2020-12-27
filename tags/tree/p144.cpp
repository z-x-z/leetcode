/// author: CagedBird
/// date: 2020/8/2
/// place: JiangXi
/// description: Another code template of leetcode's tree solution
//               using TreeSerializer to serialize or deserialize a TreeNode
#include<bits/stdc++.h>
#include"TreeNode.h"
using namespace std;


class Solution {
public:
    /// problem: 144. 二叉树的前序遍历
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<TreeNode*> treenodeStack;
        while(root!=NULL||!treenodeStack.empty())
        {
            while(root)
            {
                ans.push_back(root->val);
                treenodeStack.push(root);
                root = root->left;
            }
            root = treenodeStack.top()->right;
            treenodeStack.pop();
        }
        return ans;
    }
};

int main()
{
    Solution aSolution;
    string treeStr = "[1,2,3,4,5,6,7,null,null,null,null]";
    TreeNode* t = TreeNode::deserialize(treeStr);
    auto arr = aSolution.preorderTraversal(t);
    return 0;
}