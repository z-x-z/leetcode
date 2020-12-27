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
    /// problem: 114. 二叉树展开为链表
    void flatten(TreeNode* root)
    {
        flattenHelper(root, new TreeNode(-1));
    }
    // 按照中左右的顺序展开，则使用右左中的访问顺序，并将前一次访问的节点保存在
    // pre的右节点中
    void flattenHelper(TreeNode* node, TreeNode* pre)
    {
        if(!node)
            return;
        flattenHelper(node->right, pre);
        flattenHelper(node->left, pre);
        node->left = nullptr;
        node->right = pre->right;
        pre->right = node; // 储存前一次访问的节点
    }

};

int main()
{
    Solution aSolution;

    return 0;
}