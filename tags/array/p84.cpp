#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        // 单调栈
        vector<int> leftBound(heights.size()), rightBound(heights.size());
        stack<pair<int, int> > leftStack, rightStack;
        // 从右到左
        for (int i = 0; i < heights.size(); i++)
        {
            int height = heights[i];
            while (!leftStack.empty()&&leftStack.top().first>=height)
            {
                leftStack.pop();
            }
            leftBound[i] = leftStack.empty() ? -1: leftStack.top().second;
            leftStack.push(make_pair(height, i));
        }
        // 从左到右
        for (int i = heights.size()-1; i >=0 ; i--)
        {
            int height = heights[i];
            while (!rightStack.empty()&&rightStack.top().first>=height)
            {
                rightStack.pop();
            }
            rightBound[i] = rightStack.empty() ? heights.size(): rightStack.top().second;
            rightStack.push(make_pair(height, i));

        }
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int area = heights[i]*(rightBound[i]-leftBound[i]-1);
            if(area>maxArea)
                maxArea = area;
        }

        return maxArea;
    }
    int largestRectangleArea1(vector<int>& heights)
    {
        // 单调栈
        stack<pair<int, int> > leftStack;
        vector<int> leftBound(heights.size()), rightBound(heights.size());
        // 从右到左
        for (int i = 0; i < heights.size(); i++)
        {
            int height = heights[i];
            while (!leftStack.empty()&&leftStack.top().first>=height)
            {
                rightBound[leftStack.top().second] = i;
                leftStack.pop();
            }
            leftBound[i] = leftStack.empty() ? -1: leftStack.top().second;
            leftStack.push(make_pair(height, i));
        }
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int area = heights[i]*(rightBound[i]-leftBound[i]-1);
            if(area>maxArea)
                maxArea = area;
        }

        return maxArea;
    }


};


int main()
{
    Solution aSolution;
    vector<int> heights{6,7,5,2,4,5,9,3};
    cout<<aSolution.largestRectangleArea1(heights);
}