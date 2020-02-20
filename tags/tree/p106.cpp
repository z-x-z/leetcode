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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    TreeNode* buildTree(vIter in1, vIter in2, vIter post1, vIter post2)
    {
        if(in1==in2) return NULL;
        int rootVal = *(post2-1);
        TreeNode* root = new TreeNode(rootVal);
        auto ti = in2-1;
        auto tp = post2-1;
        int n = 0;
        while(*ti!=rootVal)
        {
            ti--;
            n++;
        }
        tp-=n;
        root->left = buildTree(in1, ti, post1, tp);
        root->right = buildTree(ti+1, in2, tp, post2-1);
        return root;
    }
};

int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution aSolution;
    aSolution.buildTree(inorder, postorder)->backOrder();
}