#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int tmp = k, mex;
    for (int i = 0;; i++)
    {
        if (!mp.count(i))
        {
            if (tmp)
            {
                tmp--;
            }
            else
            {
                mex = i;
                break;
            }
        }
    }
    set<pair<int, int>> sp;
    for (auto &[x, y] : mp)
    {
        if (x > mex)
        {
            sp.insert({y, x});
        }
    }

    while (sp.size() && k >= sp.begin()->first)
    {
        k -= sp.begin()->first;
        sp.erase(sp.begin());
    }
    cout << sp.size() << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
        /* code */
    }
}