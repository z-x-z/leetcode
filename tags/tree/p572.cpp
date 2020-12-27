/// author: CagedBird
/// date: 2020/1/5
/// place: BeiJing
/// description: A code template of leetcode's tree solution
#include <bits/stdc++.h>

#define null LONG_MAX

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    static TreeNode *init(const vector<long> &vals)
    {
        int n = vals.size();
        if (n == 0 || vals[0] == null)
            return nullptr;
        TreeNode *root = new TreeNode(vals[0]);
        queue<TreeNode *> treeQueue;
        treeQueue.push(root);
        for (int i = 0; i < n / 2; i++)
        {
            TreeNode *node = treeQueue.front();
            treeQueue.pop();
            if (vals[i * 2 + 1] != null)
            {
                node->left = new TreeNode(vals[i * 2 + 1]);
                treeQueue.push(node->left);
            }
            if (i * 2 + 2 < n && vals[i * 2 + 2] != null)
            {
                node->right = new TreeNode(vals[i * 2 + 2]);
                treeQueue.push(node->right);
            }
        }
        return root;
    }

    static void levelOrder(TreeNode *root)
    {
        printf("LevelOrder:");
        queue<TreeNode *> treeQueue;
        if (root)
        {
            printf(" %d", root->val);
            treeQueue.push(root);
        }
        else
        {
            printf(" null");
        }
        while (!treeQueue.empty())
        {
            TreeNode *node = treeQueue.front();
            treeQueue.pop();
            if (node->left)
            {
                printf(" %d", node->left->val);
                treeQueue.push(node->left);
            }
            else
            {
                printf(" null");
            }
            if (node->right)
            {
                printf(" %d", node->right->val);
                treeQueue.push(node->right);
            }
            else
            {
                printf(" null");
            }
        }
    }
    static void inOrder(TreeNode *root)
    {
        printf("Inorder:");
        stack<TreeNode *> inStack;
        while (!inStack.empty() || root != NULL)
        {
            while (root != NULL)
            {
                inStack.push(root);
                root = root->left;
            }
            root = inStack.top();
            inStack.pop();
            printf(" %d", root->val); //一定能保证现在栈中一定有元素
            root = root->right;       // 关键的一步
        }
        /*
        stack<TreeNode*> treeStack;
        TreeNode* root = node;
        while (root!=nullptr||!treeStack.empty())
        {
            if(root==nullptr)
            {
                root = treeStack.top()->right;
                treeStack.pop();
            }
            inOrderSeq.push_back(root->val);
            if(root->right)
                treeStack.push(root);
            root = root->left;
        }
        */
    }
};
class Solution;

class Solution
{
public:
    bool isSameTree(TreeNode *s, TreeNode *t)
    {
        queue<TreeNode *> sQueue, tQueue;
        sQueue.push(s);
        tQueue.push(t);
        while (!sQueue.empty() && !tQueue.empty())
        {
            TreeNode *sNode = sQueue.front();
            sQueue.pop();
            TreeNode *tNode = tQueue.front();
            tQueue.pop();
            // 若sNode,tNode都为nullPtr则跳过此轮
            if (!sNode && !tNode)
                continue;
            // 若sNode，tNode中有一者不为nullPtr则说明两者恰好为一个为null一个不为null，返回false
            // 或者两者都不为null，但两者的值不相同，也返回null
            if ((!sNode || !tNode) || (sNode->val != tNode->val))
                return false;
            sQueue.push(sNode->left);
            tQueue.push(tNode->left);
            sQueue.push(sNode->right);
            tQueue.push(tNode->right);
        }
        return true;
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        if (s->val != t->val)
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        else
            return (isSameTree(s, t)) || (isSubtree(s->left, t) || (isSubtree(s->right, t)));
    }
    void getInorderSeq(TreeNode *root, vector<long> &inorderSeq)
    {
        if (!root)
            inorderSeq.push_back(long(INT_MAX) + 1);
        else
        {
            getInorderSeq(root->left, inorderSeq);
            inorderSeq.push_back(root->val);
            getInorderSeq(root->right, inorderSeq);
        }
    }
    int isContainSubSeq(const vector<long> &v1, const vector<long> &v2)
    {
        int length1 = v1.size(), length2 = v2.size();
        for (int startI = 0, i; startI <= length1 - length2; startI++)
        {
            for (i = 0; i < length2; i++)
                if (v1[startI + i] != v2[i])
                    break;
            if (i==length2)
                return startI;
        }
        return -1;
    }
    bool isSubtree2(TreeNode *s, TreeNode *t)
    {

        vector<long> inOrderS, inOrderT;
        getInorderSeq(s, inOrderS);
        getInorderSeq(t, inOrderT);
        return isContainSubSeq(inOrderS, inOrderT);
    }
};

int main()
{
    Solution aSolution;
    TreeNode *t = TreeNode::init(vector<long>{3, 4, 5, 1, 2, null, null, 0});
    TreeNode *s = TreeNode::init(vector<long>{4, 1, 2});
    vector<long> v1, v2;
    aSolution.getInorderSeq(t, v1);
    aSolution.getInorderSeq(s, v2);
    cout << aSolution.isSubtree2(t, s);
}
/*
2147483648 0 2147483648 1 2147483648 4 2147483648 2 2147483648 3 2147483648 5 2147483648
2147483648 1 2147483648 4 2147483648 2 2147483648
True
 */