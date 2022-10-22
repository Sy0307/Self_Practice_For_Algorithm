#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define endl '\n'
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

void print(vector<ll> &a)
{
    for (auto &i : a)
        cout << i << " ";
    cout << endl;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> b(n);
    fr(i, 0, n - 1)
    {
        cin >> a[i];
    }
    b[0] = a[0];
    fr(i, 1, n - 1)
    {
        b[i] = a[i] + b[i - 1];
    }
    // print(b);
    while (q--)
    {
        ll step;
        cin >> step;
        auto pos = lower_bound(a.begin(), a.end(), step) - a.begin() - 1;
        if (pos == -1)
        {
            if (step >= a[0])
            {
                pos++;
            }
            else
            {
                cout << 0 << " ";
            }
        }
        while(pos<=n-2&&a[pos+1]<=step)
        {
            pos++;
        }
        if(pos>=0)cout << b[pos] << " ";
        // else cout<<0<<" ";
    }
    cout << endl;
}
signed main()
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