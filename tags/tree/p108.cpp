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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return buildCompleteAVLTree(nums, 0, nums.size());
    }
    TreeNode* buildCompleteAVLTree(vector<int>& nums, int start, int end)
    {
        if(end-start<=1)
        {
            if(end-start==1) return new TreeNode(nums[start]);
            else return NULL;
        } 
        int midIndex = (start+end)/2;
        TreeNode* node = new TreeNode(nums[midIndex]);
        node->left = buildCompleteAVLTree(nums, start, midIndex);
        node->right = buildCompleteAVLTree(nums, midIndex+1, end);
        return node;
    }
};

int main()
{
    Solution aSolution;
    vector<int> sortedNums {-10,-3,0,5,9}; // 列表初始化在c11中可以用
    TreeNode* root = aSolution.sortedArrayToBST(sortedNums);
    int a = 0;

}