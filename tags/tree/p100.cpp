/// author: CagedBird
/// date: 2020/1/5
/// place: BeiJing
/// description: A code template of leetcode's tree solution
#include<bits/stdc++.h>

//Binary TreeNode Implemention
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 中-左-右遍历
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL&&q==NULL) return true;
        // 前面已经判断了p、q全部为NULL的情况，现在只需判断其中一者为NULL则表示另一者为非NULL
        if((p==NULL||q==NULL)||(p->val!=q->val)) return false;
        return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
        // if(!isSameTree(p->left, q->left)) return false;
        // return isSameTree(p->right, q->right);
    }
};

int main()
{
    Solution aSolution;
    
}