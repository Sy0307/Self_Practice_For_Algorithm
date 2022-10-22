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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    fr(i, 0, n - 1)
    {
        cin >> a[i];
    }
    fr(i, 0, n - 1)
    {
        cin >> b[i];
    }
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        c[i] = b[x] - a[i];
        d[i] = b[j] - a[i];

        if (x == i)
        {
            j = i - 1;
        }
    }
    fr(i, 0, n - 1) cout << c[i] << " \n"[i == n - 1];
    fr(i, 0, n - 1) cout << d[i] << " \n"[i == n - 1];
    // cout<<c<<"\n"<<d<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}