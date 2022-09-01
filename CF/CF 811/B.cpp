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

int cnt;
bool vis[maxn];
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int,int> mp;
    fr(i,1,n)
    {
        cin>>a[i];
    }
    ford(i,n,1)
    {
        if(!mp[a[i]])
        {
            mp[a[i]]++;
        }
        else
        {
            cout<<i<<endl;
            return;
        }
    }
    cout<<0<<endl;;
    return;
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