/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class CQueue
{
private:
    stack<int> stackIn;
    stack<int> stackOut;
public:
    /// 剑指 Offer 09. 用两个栈实现队列
    CQueue()
    {

    }

    void appendTail(int value)
    {
        stackIn.push(value);
    }

    int deleteHead()
    {
        if(!stackOut.empty())
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        if(!stackOut.empty())
        {
            int value = stackOut.top();
            stackOut.pop();
            return value;
        }
        else
            return -1;
    }
};
int main()
{
    CQueue cqueue;
    cqueue.appendTail(1);
    cqueue.appendTail(2);
    cqueue.appendTail(3);
    cout<<cqueue.deleteHead()<<endl;
    cqueue.appendTail(4);
    cout<<cqueue.deleteHead()<<endl;


}