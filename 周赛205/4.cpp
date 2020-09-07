#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int fa[100005];

    int fd(int x)
    {
        if (fa[x] != x)
        {
            fa[x] = fd(fa[x]);
        }
        else
        {
            return fa[x];
        }
        return fa[x];
    }
    void un(int x, int y)
    {
        int a, b;
        a = fd(x);
        b = fd(y);
        if (a != b)
        {
            fa[a] = b;
        }
    }
    void init()
    {
        for (int i = 1; i < 100005; i++)
            fa[i] = i;
    }
    bool ck(int n)
    {
        map<int, int> mp;
        //cout<<n<<endl;
        for (int i = 1; i <= n; i++)
        {
            //cout<<fd(i)<<" ";
            mp[fd(i)]++;
        }
        // cout<<mp.size()<<endl;
        if (mp.size() > 1)
            return 0;
        return 1;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        int e3 = 0;

        int e2, e1;
        e2 = e1 = 0;
        int res = 0;
        init();
        for (auto v : edges)
        {
            if (v[0] == 3)
            {
                if (fd(v[1]) != fd(v[2]))
                {
                    un(v[1], v[2]);
                    e3++;
                    res++;
                }
            }
        }
        for (auto v : edges)
        {
            if (v[0] == 1)
            {
                if (fd(v[1]) != fd(v[2]))
                {
                    un(v[1], v[2]);
                    e1++;
                    res++;
                }
            }
        }
        if (!ck(n))
            return -1;
        init();
        for (auto v : edges)
        {
            if (v[0] == 3)
            {
                if (fd(v[1]) != fd(v[2]))
                {
                    un(v[1], v[2]);
                    e3++;
                    //res++;
                }
            }
        }
        for (auto v : edges)
        {
            if (v[0] == 2)
            {
                if (fd(v[1]) != fd(v[2]))
                {
                    un(v[1], v[2]);
                    e1++;
                    res++;
                }
            }
        }
        if (!ck(n))
            return -1;

        return edges.size() - res;
    }
};

