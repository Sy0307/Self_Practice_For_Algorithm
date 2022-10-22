#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define inl inline
#define endl '\n'
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)


inl void solve()
{
    string s;
    cin >> s;
   // cout<<s<<endl;
    int n = s.size();
    // cout<<s<<endl;
    s = "?" + s;
    int idx = 1;
    vector<int> ans(0);

    while (idx <= n && s[idx] == '0')
    {
        idx++;
    }
    if(idx>n)
    {
        cout<<0<<endl;
        return ;
    }
    int cnt = 0;
    fr(i, idx, n)
    {
        if (s[i] == '0')
        {
            cnt++;
        }
        else
        {
            if (cnt)
            {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
    }
    ll tot = 0;
    if(!ans.size())
    {
        cout<<0<<endl;
        return ;
    }
    fr(i, 0, ans.size() - 1)
    {
        tot += ans[i];
    }
    cout << tot << endl;
}
int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}