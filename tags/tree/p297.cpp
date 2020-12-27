/// author: CagedBird
/// date: 2020/1/5
/// place: BeiJing
/// description: A code template of leetcode's tree solution
#include<bits/stdc++.h>

#define null LONG_MAX

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}

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

    static void levelOrder(TreeNode* root)
    {
        printf("LevelOrder:");
        queue<TreeNode* > treeQueue;
        if(root)
        {
            printf(" %d", root->val);
            treeQueue.push(root);
        }
        else {printf(" null");}
        while (!treeQueue.empty())
        {
            TreeNode* node = treeQueue.front();
            treeQueue.pop();
            if(node->left)
            {
                printf(" %d", node->left->val);
                treeQueue.push(node->left);
            }
            else {printf(" null");}
            if(node->right)
            {
                printf(" %d", node->right->val);
                treeQueue.push(node->right);
            }
            else {printf(" null");}
        }
    }
    static void inOrder(TreeNode* root)
    {
        printf("Inorder:");
        stack<TreeNode*> inStack;
        while (!inStack.empty()||root!=NULL)
        {
            while (root!=NULL)
            {
                inStack.push(root);
                root = root->left;
            }
            printf(" %d", inStack.top()->val); //一定能保证现在栈中一定有元素
            inStack.pop();
            root = root->right; // 关键的一步
        }
    }
};
class Codec
{
private:
    inline void serializeHelper(TreeNode* node, string& ans, queue<TreeNode*>& treeQueue)
    {
        ans.push_back(',');
        if(node)
        {
            ans.append(to_string(node->val));
            treeQueue.push(node);
        }
        else
            ans.append("null");
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string ans = "[";
        queue<TreeNode*> treeQueue;
        if(root!=NULL)
        {
            ans.append(to_string(root->val));
            treeQueue.push(root);
        }
        int levelLength= 0;
        while (!treeQueue.empty())
        {
            levelLength = treeQueue.size();
            for (int i = 0; i < levelLength; i++)
            {
                TreeNode* node = treeQueue.front(); treeQueue.pop();
                serializeHelper(node->left, ans, treeQueue);
                serializeHelper(node->right, ans, treeQueue);
            }
        }
        // 删除尾部多余的",null"
        int last = ans.size();
        while (last-5>0&&ans[last-4]=='n')
        {
            // substr(pos, count) -> str[pos, pos+count];
            // str[i, j] -> substr(i, j-i);
            last-=5;
        }
        // 在合适的位置插入']'字符
        ans.push_back(']');
        ans[last] = ']';
        return ans.substr(0, last+1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        vector<TreeNode*> nodes;
        // 获取所有的node并装入vector中
        for(int i = 1, endIndex = data.size()-1; i<endIndex;)
        {
            int j;
            // 得到下一个','的位置j
            for (j = i; j < endIndex&&data[j]!=','; j++) ;
            // null
            if(data[i]=='n')
                nodes.push_back(NULL);
            else
                nodes.push_back(new TreeNode(stoi(data.substr(i, j-i))));
            i = j+1;
        }
        // 将线性形式的nodes收缩成真正的树
        // root需要默认值，否则其值将会是未定义的
        TreeNode* root= nodes.empty() ? NULL: nodes[0];
        int index=1;
        queue<TreeNode* > treeQueue;
        if(root)
            treeQueue.push(root);
        while (!treeQueue.empty())
        {
            for (int i = 0, length = treeQueue.size(); i < length; i++)
            {
                TreeNode* node = treeQueue.front();
                treeQueue.pop();
                if(index<nodes.size())
                {
                    node->left = nodes[index++];
                    if(node->left)
                        treeQueue.push(node->left);
                }
                if(index<nodes.size())
                {
                    node->right = nodes[index++];
                    if(node->right)
                        treeQueue.push(node->right);
                }
            }
        }
        return root;
    }
};

int main()
{
    Codec codec;
    string data = "[5,2,3,null,null,2,4,3,1]";
    TreeNode* node =  codec.deserialize(data);
    /* TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->right->left = new TreeNode(4);
    node->right->right = new TreeNode(5); */
    cout<<"After deserialize"<<endl;
    TreeNode::levelOrder(node);
    cout<<endl;
    cout<<"After serialize"<<endl;
    cout<<codec.serialize(node)<<endl;
}