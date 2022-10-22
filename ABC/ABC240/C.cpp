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

int dp[110][10010];
int a[110], b[110];
void solve()
{
    int n,x;
    cin >> n>>x;
    fr(i, 1, n)
    {
        cin >> a[i];
        cin >> b[i];
    }
    dp[0][0] = 1;
    fr(i, 1, n)
    {
        fr(j, 0, x)
        {
            if (j >= a[i])
                dp[i][j] |= dp[i - 1][j - a[i]];
            if (j >= b[i])
                dp[i][j] |= dp[i - 1][j - b[i]];
        }
    }
    if (dp[n][x])
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}