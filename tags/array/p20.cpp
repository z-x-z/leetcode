#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int totalLength = nums1.size() + nums2.size();
        if(totalLength%2==0)
        {
            double d1 = getKthInTwoArray(totalLength/2 , nums1, nums2);
            cout<<d1<<endl;
            double d2 = getKthInTwoArray( totalLength / 2 +1, nums1, nums2);
            cout<<d2<<endl;
            return (d1+d2)/2;
        }
        else return getKthInTwoArray( totalLength / 2 +1, nums1, nums2);
    }
    // 通过二分法获取两个有序数组合并后的第k小(k从1开始的元素
    double getKthInTwoArray(int k, vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = 0, l1 = nums1.size();
        int s2 = 0, l2 = nums2.size();
        int m1, m2;
        assert(k <= (l1 + l2));
        while (k!=1)
        {
            // 消去前 k/2 个元素
            int m = k/2;
            int im = m-1;
            // 两序列中有且仅有一个序列出现"m > li"的情况
            if (m> l1)
            {
                s2 += m;
                l2 -= m;
            }
            else if (m > l2)
            {
                s1 += m;
                l1 -= m;
            }
            //比较两者的第m(下标为m-1)的元素
            // 较小的那个序列的前m个元素一定不是要找的第k小的元素
            // 故可以直接将其删去
            else
            {
                if(nums1[s1+im]<=nums2[s2+im])
                {
                    s1 += m;
                    l1 -= m;
                }
                else
                {
                    s2+=m;
                    l2-=m;
                }
            }
            k-=m;
        }
        if (l1 == 0 && l2 != 0)
            return nums2[s2];
        if (l2 == 0 && l1 != 0)
            return nums1[s1];
        // 最终k=1，此时只要比较两者之中首元素的较小者即可
        return nums1[s1] < nums2[s2] ? nums1[s1] : nums2[s2];
    }
};
int main()
{
    vector<int> vec1, vec2;
    vec1.push_back(1);
    vec1.push_back(2);
    int a;
    cin>>a;
    // 
    vec2.push_back(3);
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.push_back(6);
    vec2.push_back(7);
    printf("%.1f", Solution().findMedianSortedArrays(vec1, vec2));
}
