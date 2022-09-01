#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

const int maxn = 1e5 + 10;
int n, a[maxn], ans, siz;
bool occ[maxn];

int handle(int k)
{
    memset(occ, 0, sizeof(occ));
    int ans = 0, cnt = 0, sta = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!occ[a[i]])
        {
            cnt++;
            occ[a[i]] = 1;
        }
        if (cnt > k)
        {
            ans++;
            cnt = 1;
            for (int j = sta; j <= i; j++)
            {
                occ[a[j]] = 0;
            }
            sta = i;
            occ[a[i]] = 1;
        }
    }
    if (cnt)
        ans++;
    return ans;
}
void solve()
{
    cin >> n;
    siz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int k = 1; k <= n; k++)
    {
        if (k <= siz)
            cout << handle(k) << " ";
        else
        {
            ans = handle(k);
            int l = k, r = n;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (handle(mid) < ans)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            for (int i = k; i <= l - 1; i++)
            {
                cout << ans << " ";
            }
            k = l - 1;
        }
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T=1;
    while (T--)
    {
        solve();
    }
    return 0;
}