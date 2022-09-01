#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxv = 1e6;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
bool vis[maxv+10];
void solve()
{
    int n;
    cin >> n;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= maxv; i++)
    {
        if (vis[i])
            continue;
        int res = 0;
        for (int j = 2 * i; j <= maxv; j += i)
        {
            if (vis[j])
                res = gcd(res, j/i );
        }
        if (res == 1)
            ans++;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
  //  cout<<gcd(0,19)<<endl;
    return 0;
}