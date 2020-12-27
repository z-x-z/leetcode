/// author: CagedBird
/// date: 2020/6/23
/// place: JiangXi
/// description: Another code template of leetcode's tree solution
//               using TreeSerializer to serialize or deserialize a TreeNode
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    /// problem: 124. 二叉树中的最大路径和

    // 获得每个节点的左子树路径最大值与右子树路径最大值并存入相应leftTree与rightTree的节点值中
    pair<int, int> buildCrossTree(TreeNode *originalTree, TreeNode *leftTree, TreeNode *rightTree)
    {
        pair<int, int> leftPair, rightPair;
        if (originalTree->left)
        {
            leftTree->left = new TreeNode();
            rightTree->left = new TreeNode();
            leftPair = buildCrossTree(originalTree->left, leftTree->left, rightTree->left);
            leftTree->val = max(0, max(leftPair.first, leftPair.second)) + originalTree->left->val;
        }
        if (originalTree->right)
        {
            leftTree->right = new TreeNode();
            rightTree->right = new TreeNode();
            rightPair = buildCrossTree(originalTree->right, leftTree->right, rightTree->right);
            rightTree->val = max(0, max(rightPair.first, rightPair.second)) + originalTree->right->val;
        }
        return make_pair(leftTree->val, rightTree->val);
    }
    // 分治法
    // 每个节点所在的树的最大路径值要么是其子树的最大值，要么是包含根节点在内的路径值
    int maxPathSumCore(TreeNode *root, TreeNode *leftTree, TreeNode *rightTree)
    {
        if (!root)
            return INT_MIN;
        int SubTreeVal = maxPathSumCore(root->left, leftTree->left, rightTree->left);
        SubTreeVal = max(SubTreeVal, maxPathSumCore(root->right, leftTree->right, rightTree->right));
        int crossTreeVal = root->val;
        if (leftTree->val > 0)
            crossTreeVal += leftTree->val;
        if (rightTree->val > 0)
            crossTreeVal += rightTree->val;
        return max(SubTreeVal, crossTreeVal);
    }
    int maxPathSum(TreeNode *root)
    {
        TreeNode *leftTree = new TreeNode();
        TreeNode *rightTree = new TreeNode();
        buildCrossTree(root, leftTree, rightTree);
        return maxPathSumCore(root, leftTree, rightTree);
    }

    // 递归方法
    int maxPathSum2Helper(TreeNode *root, int &maxSum)
    {
        if (!root)
            return 0;
        int leftVal = max(0, maxPathSum2Helper(root->left, maxSum));
        int rightVal = max(0, maxPathSum2Helper(root->right, maxSum));
        maxSum = max(maxSum, root->val + leftVal + rightVal);
        return root->val + max(leftVal, rightVal);
    }
    int maxPathSum2(TreeNode *root)
    {
        int maxSum = 0;
        if (root)
            maxPathSum2Helper(root, maxSum);
        return maxSum;
    }
};

int main()
{
    Solution aSolution;
    // string str = "[-10,9,20,null,5,15,7]";
    string str = "[9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]";
    TreeNode *root = TreeNode::deserialize(str);
    TreeNode::levelOrder(root);
    cout << aSolution.maxPathSum2(root);
    return 0;
}