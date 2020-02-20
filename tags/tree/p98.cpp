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
    bool isValidBST(TreeNode* root) 
    {
        if(!root) return true;
        bool flag = true;
        if(root->left) flag = flag&&root->val>root->left->val&&isLeftValid(root->left, root->val);
        if(root->right) flag = flag&&root->val<root->right->val&&isRightValid(root->right, root->val);
        return flag;
    }
    bool isLeftValid(TreeNode* node, int maxVal, long minVal= (long)INT_MIN-1)
    {
        if(node->val>=maxVal||node->val<=minVal) return false;
        bool flag = true;
        if(node->left) flag = flag&&node->val>node->left->val&&isLeftValid(node->left, node->val, minVal);
        if(node->right) flag = flag&&node->val<node->right->val&&isRightValid(node->right, node->val, maxVal);
        return flag;
    }
    bool isRightValid(TreeNode* node, int minVal, long maxVal= (long)INT_MAX+1)
    {
        if(node->val>=maxVal||node->val<=minVal) return false;
        bool flag = true;
        if(node->left) flag = flag&&node->val>node->left->val&&isLeftValid(node->left, node->val, minVal);
        if(node->right) flag = flag&&node->val<node->right->val&&isRightValid(node->right, node->val, maxVal);
        return flag;
    }
    bool isValidBST_inOrder(TreeNode* root)
    {
        std::stack<TreeNode*> inOrderStack;
        // 中序遍历，左中右
        long before = (long)INT_MIN-1;
        while(!inOrderStack.empty()||root!=NULL)
        {
            while (root)
            {
                inOrderStack.push(root);
                root= root->left;
            }
            root = inOrderStack.top(); inOrderStack.pop();
            if(root->val<=before) return false;
            root = root->right;
        }
        return true;
    }
};

int main()
{
    Solution aSolution;
}