#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char fd(char p, char s)//选择一个合适的小写字母
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (c != p && c != s)
            {
                return c;
            }
        }
        return '#';
    }
    string modifyString(string s)
    {
        string t = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '?')
            {
                t += s[i];
            }
            else
            {
                char x, y;
                if (i - 1 < 0)
                {
                    x = '#';
                }
                else
                {
                    x = t[i - 1];
                }
                if (i + 1 > s.length() - 1 || s[i + 1] == '?')
                {
                    y = '#';
                }
                else
                {
                    y = s[i + 1];
                }
                char tp = fd(x, y);
                t += tp;
            }
        }
        return t;
    }
};
