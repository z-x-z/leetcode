/// author: CagedBird
/// date: 2020/1/5
/// place: BeiJing
/// description: A code template of leetcode's tree solution
#include<bits/stdc++.h>

#define null LONG_MAX

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    static TreeNode* init(vector<long> vals)
    {
        int n = vals.size();
        if(n==0||vals[0]==null) return NULL;
        TreeNode* root = new TreeNode(vals[0]);
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        for (int i = 0; i < n/2; i++)
        {
            TreeNode* node = treeQueue.front();
            treeQueue.pop();
            if(vals[i*2+1]!=null)
            {
                node->left = new TreeNode(vals[i*2+1]);
                treeQueue.push(node->left);
            }
            if(vals[i*2+2]!=null)
            {
                node->right = new TreeNode(vals[i*2+2]);
                treeQueue.push(node->right);
            }
        }
        return root;
    }

    static void levelOrder(TreeNode* root)
    {
        printf("LevelOrder:");
        queue<TreeNode* > treeQueue;
        if(root) 
        {
            printf(" %d", root->val);
            treeQueue.push(root);
        }
        else {printf(" null");}
        while (!treeQueue.empty())
        {
            TreeNode* node = treeQueue.front();
            treeQueue.pop();
            if(node->left)
            {
                printf(" %d", node->left->val);
                treeQueue.push(node->left);
            } 
            else {printf(" null");}
            if(node->right)
            { 
                printf(" %d", node->right->val);
                treeQueue.push(node->right);
            }
            else {printf(" null");}
        }
    }
    static void inOrder(TreeNode* root)
    {
        printf("Inorder:");
        stack<TreeNode*> inStack;
        while (!inStack.empty()||root!=NULL)
        {
            while (root!=NULL)
            {
                inStack.push(root);
                root = root->left;
            }
            printf(" %d", inStack.top()->val); //一定能保证现在栈中一定有元素
            inStack.pop();
            root = root->right; // 关键的一步
        }
    }
};
class Solution;

class Solution {
public:
    
};

int main()
{
    Solution aSolution;
    
}