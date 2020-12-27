/*
 * @Author: your name
 * @Date: 2020-07-07 21:07:27
 * @LastEditTime: 2020-12-27 15:26:15
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /leetcode/tags/tree/p112.cpp
 */
/// author: CagedBird
/// date: 2020/07/07
/// place: JiangXi
/// description: Another code template of leetcode's tree solution
//               using TreeSerializer to serialize or deserialize a TreeNode

#include<bits/stdc++.h>
#include"TreeNode.h"
using namespace std;


class Solution {
public:
    /// problem:
    bool hasPathSum(TreeNode* root, int sum)
    {
        queue<pair<TreeNode*, int> > pathQueue;
        if(root)
            pathQueue.emplace(root, sum);
        while (!pathQueue.empty())
            for (int i = 0, length= pathQueue.size(); i < length; i++)
            {
                auto aPair = pathQueue.front();
                pathQueue.pop();
                if((sum = aPair.second-aPair.first->val)==0&&!aPair.first->left&&!aPair.first->right)
                    return true;
                if(aPair.first->left)
                    pathQueue.emplace(aPair.first->left, sum);
                if(aPair.first->right)
                    pathQueue.emplace(aPair.first->right, sum);
            }
        return false;
    }
};

int main()
{
    Solution aSolution;

    return 0;
}