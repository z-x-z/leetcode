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
    static void preOrder(TreeNode* root)
    {
        printf("%d ", root->val);
        if(root->left) preOrder(root->left);
        if(root->right) preOrder(root->right);
    }
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int s, int e)
    {
        vector<TreeNode*> results;
        if(s>e) {results.push_back(NULL);} 
        else if(s==e) {results.push_back(new TreeNode(s));}
        else 
        {
            for (int i = s; i <= e; i++)
            {
                vector<TreeNode*> left = generateTrees(s, i-1);
                vector<TreeNode*> right = generateTrees(i+1, e);
                for (auto l: left)
                {
                    for (auto r: right)
                    {
                        TreeNode* root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        results.push_back(root);
                    }
                }
            }
        }
        return results;
    }

    vector<TreeNode*> generateTrees(int n) 
    {
        if(n==0)
        {
            vector<TreeNode*> results;
            results.push_back(NULL);
            return results;
        } 
        return generateTrees(1, n);
    }
    
};

int main()
{
    Solution aSolution;
    auto result = aSolution.generateTrees(1, 3);
    for (auto tree: result)
    {
        TreeNode::preOrder(tree);
        printf("\n");
    }
    //What's your name?
    string name = "hello world";
}