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
const int maxn = 1 << 21;
ll a[maxn];
ll t[100][3];
ll n, m;
void merge_sort(int l, int r, int k)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid, k - 1);
    merge_sort(mid + 1, r, k - 1);
    for (int i = l; i <= mid; i++)
    {
        t[k][1] += lower_bound(a + mid + 1, a + r + 1, a[i]) - (a + mid + 1);
        t[k][0] += (a + r + 1) - upper_bound(a + mid + 1, a + r + 1, a[i]);
    }
    sort(a + l, a + r + 1);
}

void solve()
{
    
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        cin >> a[i];
    }
    merge_sort(0, (1 << n) - 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        for (int i = 1; i <= x; i++)
        {
            swap(t[i][0], t[i][1]);
        }
        ll res = 0;
        for (int i = 1; i <= n; i++)
            res += t[i][1];
        cout << res << endl;
    }
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
    return 0;
}