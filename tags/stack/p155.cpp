#include<bits/stdc++.h>
using namespace std;



class MinStack
{
public:
    /** initialize your data structure here. */
    // 辅助栈
    stack<pair<int, int> > minStack;

    MinStack()
    {
        minStack = stack<pair<int, int> >();
    }

    void push(int x)
    {
        int minElement;
        if(minStack.empty()|| minStack.top().second>x)
            minElement = x;
        else
            minElement = minStack.top().second;
        minStack.push(make_pair(x, minElement));
    }

    void pop()
    {
        minStack.pop();
    }

    int top()
    {
        return minStack.top().first;
    }

    int getMin()
    {
        return minStack.top().second;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main()
{
    MinStack minStack;
    minStack.push(1);
    cout<<minStack.getMin();
    minStack.push(3);
    cout<<minStack.getMin();
    minStack.push(5);
    cout<<minStack.getMin();
    minStack.push(0);
    cout<<minStack.getMin();
}

