#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string soluction1(string& s)
    {
        int n = s.size();
        if (n <= 1)
            return s;
        bool isPalindrome[n][n];
        for (int i = 0; i < n - 1; i++)
        {
            int start = i, end = i + 1;
            isPalindrome[start][end] = s[start] == s[end];
            start--;
            end++;
            while (start >= 0 && end < n)
            {
                isPalindrome[start][end] = (isPalindrome[start + 1][end - 1] && s[start] == s[end]);
                start--;
                end++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            isPalindrome[i][i] = true;
            int start = i - 1;
            int end = i + 1;
            while (start >= 0 && end < n)
            {
                isPalindrome[start][end] = (isPalindrome[start + 1][end - 1] && s[start] == s[end]);
                start--;
                end++;
            }
        }
        int mi = 0, mj = 0;
        int maxL = 0;
        for (int i = 0; i < n; i++)
        { 
            for (int j = i + 1; j < n; j++)
            {
                if (j - i + 1 > maxL && isPalindrome[i][j])
                {
                    mi = i;
                    mj = j;
                    maxL = j - i + 1;
                }
            }
        }
        return s.substr(mi, mj - mi + 1);
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        if(n<=1) return s;
        bool isPalindrome[n][n];
        int start, end, len;
        int maxLen = 1, ms= 0;
        // 起始点start与长度len决定唯一的决定了一个子串
        for(int start=0;start<n;start++) isPalindrome[start][start] = true;
        for(len = 2;len<=n;len++)
        {   
            for(start = 0 ;start<n-1;start++)
            {
                end = start+len-1;
                if(end>=n) break;
                isPalindrome[start][end] = (s[start]==s[end])&&(len==2||isPalindrome[start+1][end-1]);
                // isPalindrome[start][end] = (len==1)||(len==2&&s[start]==s[end])||(isPalindrome[start+1][end-1]&&(s[start]==s[end]));
                if(isPalindrome[start][end]&&len>maxLen)
                {
                    maxLen = len;
                    ms = start;
                }
            }
        }
        return s.substr(ms, maxLen);
        
    }
};

int main()
{
    Solution aSolution;
    string str = "abcdeeedcacbs";
                //0123456789
    string result = aSolution.longestPalindrome(str);
    cout << result << endl;
}