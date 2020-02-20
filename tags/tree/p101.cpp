/// author: CagedBird
/// date: 2020/1/5
/// place: BeiJing
/// description: A code template of leetcode's tree solution
#include<bits/stdc++.h>

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
    bool isSymmetric(TreeNode* root) 
    {
        if(!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if(!left&&!right) return true;
        if((!left||!right)||(left->val!=right->val)) return false;
        return isSymmetric(left->left, right->right)&&isSymmetric(left->right, right->left);
    }
    bool isSymmetric_recur(TreeNode* root)
    {
        if(!root) return true;
        std::queue<TreeNode*> treeQueue;
        treeQueue.push(root->left); // left
        treeQueue.push(root->right); // right
        while (!treeQueue.empty())
        {
            TreeNode* left = treeQueue.front(); treeQueue.pop();
            TreeNode* right = treeQueue.front(); treeQueue.pop();
            if(!left&&!right) continue; // 捕捉left与right都为NULL都情况
            else if((!left||!right)||(left->val!=right->val)) return false;
            treeQueue.push(left->left);
            treeQueue.push(right->right);
            treeQueue.push(left->right);
            treeQueue.push(right->left);
        }
        return true;
    }
};

int main()
{
    Solution aSolution;
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    std::cout<<aSolution.isSymmetric_recur(tree);
}