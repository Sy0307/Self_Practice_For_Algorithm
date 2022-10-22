#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1000005;
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

int n, d, maxx;
int a[maxn];
int stmin[maxn][21];
int stmax[maxn][21];

int query(int l, int r)
{
    int t = log2(r - l + 1);
    int maxn = std::max(stmax[l][t], stmax[r - (1 << t) + 1][t]);
    int minn = std::min(stmin[l][t], stmin[r - (1 << t) + 1][t]);
    return maxn - minn;
}
void solve()
{
    cin >> n >> d;
    maxx = INT_MIN;
    memset(stmin, 0x3f, sizeof(stmin));
    for (int x, y, i = 1; i <= n; i++)
    {
        cin>>x>>y;
        maxx = std::max(maxx, x);
        stmax[x][0] = std::max(stmax[x][0], y);
        stmin[x][0] = std::min(stmin[x][0], y);
    }
    int t = log2(maxx);
    for (int j = 1; j <= t; j++)
    {
        for (int i = 1; i <= maxx - (1 << j) + 1; i++)
        {
            stmax[i][j] = std::max(stmax[i][j - 1], stmax[i + (1 << j - 1)][j - 1]);
            stmin[i][j] = std::min(stmin[i][j - 1], stmin[i + (1 << j - 1)][j - 1]);
        }
    }
    auto check = [&](int x) -> decltype(true)
    {
        for (int i = 1; i <= maxx - x; i++)
        {
            int las = x + i;
            if (query(i, las) >= d)
                return true;
        }
        return false;
    };
    int ans = -1;
    int l = 1, r = maxx;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}