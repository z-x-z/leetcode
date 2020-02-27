/// author: CagedBird
/// date: 2020/1/5
/// place: BeiJing
/// description: A code template of leetcode's tree solution
#define null LONG_MAX
#include<bits/stdc++.h>
using namespace std;
// Binary TreeNode Implemention
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    static TreeNode* init(long* vals, int n)
    {
        if(n==0||vals[0]==null) return NULL;
        TreeNode* root = new TreeNode(vals[0]);
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        for (size_t i = 0; i < n/2; i++)
        {
            TreeNode* node = treeQueue.front();
            treeQueue.pop();
            if(vals[2*i+1]!=null) treeQueue.push(node->left = new TreeNode(vals[2*i+1]));
            if(vals[2*i+2]!=null) treeQueue.push(node->right = new TreeNode(vals[2*i+2]));
        }
        return root;
    }

    static void inOrder(TreeNode* root)
    {
        if(root->left) inOrder(root->left);
        printf("%d ", root->val);
        if(root->right) inOrder(root->right);
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        return root==NULL || getDepth(root) != -2;
    }
    int getDepth(TreeNode* node)
    {
        if(!node->left&&!node->right) return 0;
        int leftDepth = node->left ? getDepth(node->left)+1 : 0;
        if(leftDepth==-1) return -2;
        int rightDepth = node->right ? getDepth(node->right)+1 : 0;
        if(rightDepth==-1||abs(leftDepth-rightDepth)>=2) return -2;
        return leftDepth > rightDepth ? leftDepth : rightDepth;
    }
};

int main()
{
    Solution aSolution;
    long vals[] = {1,2,2,3,3,null,null,4,4};
    cout<<aSolution.isBalanced(TreeNode::init(vals, 9));
    cout<<"hello"<<endl;
}