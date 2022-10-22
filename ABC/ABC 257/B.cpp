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

bool vis[210];
int pos[1010];
void solve()
{
    int n, k, q;
    cin>>n>>k>>q;
    fr(i, 1, k)
    {
        int x;
        cin >> x;
        vis[x] = 1;
        pos[i] = x;
    }
    while(q--)
    {
        int x;cin>>x;
        int now = pos[x];
        if(!vis[now+1]&&now+1<=n)
        {
            vis[now] = 0;
            pos[x] = now+1; 
            vis[now+1] = 1;
        }
    }
    fr(i,1,k)
    {
        cout<<pos[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}