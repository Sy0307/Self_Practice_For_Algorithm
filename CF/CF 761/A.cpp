#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    map<char, int> mp;
    for (auto ch : s)
    {
        mp[ch]++;
    }
    if (t == "abc" && mp['a'] && mp['b'] && mp['c'])
    {
        for (int i = 1; i <= mp['a']; i++)
        {
            cout << "a";
        }
        for (int i = 1; i <= mp['c']; i++)
        {
            cout << "c";
        }
        for (int i = 1; i <= mp['b']; i++)
        {
            cout << "b";
        }
        for (auto &now : mp)
        {
            if(now.first!='a'&&now.first!='b'&&now.first!='c')
            {
                for (int i = 1; i <= now.second; i++)
                {
                    cout << now.first;
                }
            }
        }
        cout << endl;
        return;
    }
    for (auto &now : mp)
    {
        {
            for (int i = 1; i <= now.second; i++)
            {
                cout << now.first;
            }
        }
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}