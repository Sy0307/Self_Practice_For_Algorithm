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

int cnt = 0;
int n, k;
vector<int> ans;
void get(int x)
{
    if (cnt == k - 1)
    {
        cnt++;
        ans.push_back(x);
        return;
    }
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            cnt++;
            ans.push_back(i);
            get(x / i);
            break;
        }
    }
}
void solve()
{
    // int n,k;
    cin >> n >> k;
    get(n);
    if (cnt < k)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        //ll res = 1;
        for (int i = 0; i < k; i++)
        {
             cout << ans[i] << " ";
        }
    //    cout << res << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}