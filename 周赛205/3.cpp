#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCost(string s, vector<int> &cost)
    {
        stack<char> st;
        int sum, mx;
        int res = 0;
        sum = 0;
        mx = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
                sum = cost[i];
                mx = cost[i];
            }
            else
            {
                if (st.top() == s[i])
                {
                    st.push(s[i]);
                    sum += cost[i];
                    mx = max(mx, cost[i]);
                }
                else
                {
                    if (st.size() > 1)
                    {
                        res += (sum - mx);
                        //cout<<res<<endl;
                        // cout<<i<<endl;
                    }
                    while (!st.empty())
                    {
                        st.pop();
                    }
                    st.push(s[i]);

                    sum = mx = cost[i];
                }
            }
        }
        if (!st.empty() && st.size() > 1)
        {
            res += (sum - mx);
        }
        return res;
    }
};
