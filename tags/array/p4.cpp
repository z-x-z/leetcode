#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMid(vector<int>& nums1, vector<int>& nums2)
    {
        int i1 = nums1.size()/2, i2 = nums2.size();
        int m1 = nums1[i1], m2 = nums2[i2];
        while (true)
           {
               if (nums1[i1-1]<=m2||nums2[i2+1]>=m1)
               {
                   break;
               }
               i1++;
               i2++;
           }
           double mid = 0;
           if (nums1[i1-1]>m2)
           {
               mid = nums1[i1-1];
           }
           else if(nums2[i2+1]<m1)
           {
               mid = nums2[i2+1];
           }
           else mid= 1.0*(m1+m2)/2;
           return mid;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int i1 = nums1.size()/2, i2 = nums2.size();
        int m1 = nums1[i1], m2 = nums2[i2];
        double mid;
        if (m1>m2)
        {
           mid = findMid(nums1, nums2); 
        }
        else mid = findMid(nums2, nums1);
        return mid;
    }
};
int main()
{
    vector<int> v1, v2;
    // 1 3 5
    //  2 4 6
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);
    double mid=  Solution().findMedianSortedArrays(v1, v2);
    cout<<mid;
}