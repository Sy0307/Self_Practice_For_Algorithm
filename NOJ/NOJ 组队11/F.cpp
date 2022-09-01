#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

vector<int> a;
int n;
void pre()
{
    cin >> n;
    a.resize(n + 2);
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    a[0] = a[n+1] = INT_MAX;
}
int solve()
{
    int d1 = INT_MAX, d2 = INT_MAX;
    fr(i, 1, n)
    {
        if (a[i] < d1)
        {
            d2 = d1;
            d1 = a[i];
        }
        else if (a[i] < d2)
        {
            d2 = a[i];
        }
    }
    return (d1 + 1) / 2 + (d2 + 1) / 2;
}
int solve2()
{
    int res = INT_MAX;
    fr(i, 1, n)
    {
        res = min(res, max(max((a[i] + 1) / 2, (a[i + 1] + 1) / 2), (a[i] + a[i + 1] + 2) / 3));
    }
    return res;
}
int solve3()
{
    int res = INT_MAX;
    fr(i, 2, n)
    {
        res = min(res, min(a[i + 1], a[i - 1]) + (abs(a[i - 1] - a[i + 1]) + 1) / 2);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    int ans = INT_MAX;
    while (T--)
    {
        pre();
        ans = min(ans, solve());
        ans = min(ans, solve2());
        ans = min(ans, solve3());
    }
    cout<<ans<<endl;
    return 0;
}