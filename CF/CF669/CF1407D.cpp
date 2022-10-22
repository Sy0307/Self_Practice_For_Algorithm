#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    fr(i, 1, n)
    {
        cin >> a[i - 1];
    }
    stack<int> st1, st2;
    vector<int> dp(n, n);
    dp[0] = 0;
    st1.push(0);
    st2.push(0);
    fr(i, 1, n - 1)
    {
        // cout<<i<<endl;
        dp[i] = std::min(dp[i - 1], dp[i - 1]) + 1;
        while (st1.size() && a[i] >= a[st1.top()])
        {
            int x = a[st1.top()];
            st1.pop();
            if (st1.size() && a[i] > x)
                dp[i] = min(dp[i], dp[st1.top()] + 1);
        }



        while (st2.size() && a[i] <= a[st2.top()])
        {
            int x = a[st2.top()];
            st2.pop();
            if (st2.size() && a[i] < x)
                dp[i] = min(dp[i], dp[st2.top()] + 1);
        }
        st1.push(i);
        st2.push(i);
    }
    cout << dp[n-1] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}