#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    typedef long ll;
    map<ll, ll> m1, m2;

    int numTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = i + 1; j < nums1.size(); j++)
            {
                m1[(ll)nums1[i] * (ll)nums1[j]]++;
            }
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            for (int j = i + 1; j < nums2.size(); j++)
            {
                m2[(ll)nums2[i] * (ll)nums2[j]]++;
            }
        }
        int sum = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            sum += m2[(ll)nums1[i] * (ll)nums1[i]];
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            sum += m1[(ll)nums2[i] * (ll)nums2[i]];
        }

        return sum;
    }
};
