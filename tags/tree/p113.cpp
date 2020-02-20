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
    
    static void inOrder(TreeNode* root)
    {
        if(root->left) inOrder(root->left);
        printf("%d ", root->val);
        if(root->right) inOrder(root->right);
    }
    static void preOrder(TreeNode* root)
    {
        printf("%d ", root->val);
        if(root->left) preOrder(root->left);
        if(root->right) preOrder(root->right);
    }
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int> > results;
        vector<int> helper;
        pathSumHelper(root, sum, results, helper);
        return results;
    }
    void pathSumHelper(TreeNode* root, int sum, 
        vector<vector<int> >& results, vector<int>& helper)
    {
        if(!root) return ;
        int diff = sum - root->val;
        helper.push_back(root->val);
        if(diff==0&&!root->left&&!root->right) results.push_back(helper);
        pathSumHelper(root->left, diff, results, helper);
        pathSumHelper(root->right, diff, results, helper);
        helper.pop_back();
    }
};

int main()
{
    vector<long> vals = {5,4,8,11,null,13,4,7,2,null,null,5,1};
    TreeNode* root = TreeNode::init(vals);
    Solution aSolution;
    int a = 1;
    auto results = aSolution.pathSum(root, 22);
    for (auto result: results)
    {
        for (auto val: result)
        {
            printf("%d ", val);
        }
        printf("\n");
    }
    
}