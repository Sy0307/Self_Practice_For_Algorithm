#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
int n;
string s;
int dfs(int l, int r, char c, int nowval)
{
    if (l >= r)
    {
        return nowval + (s[l] != c);
    }
    int mid = (l + r) >> 1;

    int res1 = 0, rec1 = 0;
    for (int i = l; i <= mid; i++)
    {
        if (s[i] != c)
            rec1++;
    }
    res1 = dfs(mid + 1, r, c + 1, nowval + rec1);

    int res2 = 0, rec2 = 0;
    for (int i = mid+1; i <= r; i++)
    {
        if (s[i] != c)
            rec2++;
    }
    res2 = dfs(l, mid, c + 1, nowval + rec2);

    return min(res1, res2);
}
void solve()
{
    cin >> n;
    cin >> s;
    cout<<dfs(0, n-1, 'a',0)<<endl;;
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