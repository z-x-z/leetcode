/// author: CagedBird
/// date: 2020/1/5
/// place: BeiJing
/// description: A code template of leetcode's tree solution
#include<bits/stdc++.h>
using namespace std;

typedef vector<int>::iterator vIter;

// Binary TreeNode Implemention
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     void backOrder()
     {
        if(left) left->backOrder();
        if(right) right->backOrder();
        printf("%d ", val);        
     }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* buildTree(vIter p1, vIter p2, vIter i1, vIter i2)
    {
        if(p1 == p2) return NULL;
        TreeNode* root = new TreeNode(*p1);
        auto tp = p1;
        auto ti = i1;
        while(*ti!=*p1)
        {
            ti++; tp++;
        }
        root->left =  buildTree(p1+1, tp+1, i1, ti);
        root->right = buildTree(tp+1, p2, ti+1, i2);
        return root;
        
    }
};

int main()
{
    Solution aSolution;
    vector<int> preorder = {3, 9, 20 ,15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    aSolution.buildTree(preorder, inorder)->backOrder();
}