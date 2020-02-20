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
    int numTrees(int n) 
    {
        int results[n+1];
        results[0] = results[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            results[i] = 0;
            for (int j = 0; j < i; j++) results[i] += results[j]*results[i-j-1];
        }
        return results[n];
    }
};

int main()
{
    Solution aSolution;
    int x;
    cout<<":";
    while (cin>>x)
    {
        cout<<aSolution.numTrees(x)<<"\n:";
    }
    
}