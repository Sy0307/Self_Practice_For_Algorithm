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

int n, k;
const int INF = 1e9;
void solve()
{
    cin >> n >> k;
    vector<pii> a(n + 1);
    fr(i, 1, n)
    {
        int x;
        cin >> x;
        a[i].first = x;
        a[i].second = i;
    }
    auto p = a;
    sort(p.begin(), p.end());
    // cout<<p[1].first<<endl;
    fr(i, 1, k-1)
    {
        p[i].first = INF;
        a[p[i].second].first = INF;
    }
    sort(p.begin(), p.end());
    int res1 = INF;
    res1 = min(res1, p[n].first);
    res1 = min(res1, p[1].first * 2);
  //  cout<<res1<<endl;
    int res2 = INF;
    p[1].first = INF;
    a[p[1].second].first = INF;
    sort(p.begin(), p.end());
    res2 = min(res2, p[1].first*2);
    vector<int> b(n + 1);
    fr(i,1,n)
    {
        b[p[i].second] = p[i].first;
    }
    int tmp = -INF;
    fr(i,1,n-1)
    {
        tmp = max(tmp,min(b[i],b[i+1]));
    }
    res2 = min(tmp,res2);
    auto ans = max(res2,res1);
    cout << ans << endl;
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