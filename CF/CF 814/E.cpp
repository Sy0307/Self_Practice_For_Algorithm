#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

void solve()
{
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    fr(i, 1, n) cin >> a[i];
    deque<pii> dq;
    vector<int> ans[n + 1];

    fr(i, 1, n)
    {
        dq.push_back({a[i], i});
    }
    fr(i, 1, n)
    {
        auto k1 = dq.front();
        dq.pop_front();
        auto k2 = dq.front();
        dq.pop_front();
        if(k1.first>k2.first)
        {
            dq.push_front(k1);
            dq.push_back(k2);
            ans[k1.second].push_back(i);
        }
        else
        {
            dq.push_front(k2);
            dq.push_back(k1);
            ans[k2.second].push_back(i);
        }   
    }
    while(q--)
    {
        int i,k;
        cin>>i>>k;
        if(k<=n||a[i]!=n)
        {
            cout<<upper_bound(ans[i].begin(),ans[i].end(),k)-ans[i].begin()<<endl;
        }
        else
        {
            cout<<max(0,k-n)+upper_bound(ans[i].begin(),ans[i].end(),k)-ans[i].begin()<<endl;
        }
    }
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