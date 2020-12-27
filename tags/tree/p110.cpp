/// author: CagedBird
/// date: 2020/1/5
/// place: BeiJing
/// description: A code template of leetcode's tree solution
#define null LONG_MAX
#include<bits/stdc++.h>
#include"TreeNode.h"
using namespace std;

class Solution {
public:
    int isBanlancedHelper(TreeNode* node)
    {
        if(!node)
            return 0;
        int ld, rd;
        if((ld = isBanlancedHelper(node->left))<0||(rd = isBanlancedHelper(node->right))<0||abs(ld-rd)>1)
            return -1;
        else
            return max(ld, rd)+1;
    }
    bool isBalanced(TreeNode* root)
    {
        return isBanlancedHelper(root)>=0;
        // return root==NULL || getDepth(root) != -2;
    }
    /* int getDepth(TreeNode* node)
    {
        if(!node->left&&!node->right) return 0;
        int leftDepth = node->left ? getDepth(node->left)+1 : 0;
        if(leftDepth==-1) return -2;
        int rightDepth = node->right ? getDepth(node->right)+1 : 0;
        if(rightDepth==-1||abs(leftDepth-rightDepth)>=2) return -2;
        return leftDepth > rightDepth ? leftDepth : rightDepth;
    } */
};

int main()
{
    Solution aSolution;
    string treeStr = "[1,2,2,3,3,null,null,4,4]";
    cout<<aSolution.isBalanced(TreeNode::deserialize(treeStr));
}