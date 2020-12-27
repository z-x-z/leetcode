/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
// hugghgh
    string addBinary(string a, string b)
    {
        int aSize = a.size(), bSize = b.size();
        int maxSize = max(aSize, bSize);
        vector<bool> bits(maxSize + 1, true);
        bool bit_a, bit_b, carry = false;
        for (int i = 0; i < maxSize; i++)
        {
            bit_a = bit_b = false;
            if (i < aSize && a[aSize - i - 1] == '1')
                bit_a = true;
            if (i < bSize && b[bSize - i - 1] == '1')
                bit_b = true;
            bits[i] = (bit_a ^ bit_b) ^ carry;
            carry = carry ? bit_a|bit_b : bit_a&bit_b;
            cout << bits[i] << " " << carry << endl;
        }
        int i = maxSize;
        if (!carry)
            i--;
        string ans(i+1, '0');
        for (int j =i; j >= 0; j--)
            if (bits[j])
                ans[i-j] = '1';
        return ans;
    }
};

int main()
{
    Solution aSolution;
    string a = "111";
    string b = "1";
    cout << aSolution.addBinary(a, b);
}
