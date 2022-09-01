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

int fa[maxn];
void solve()
{
    int n;
    cin >> n;
    fr(i,2,n)
    {
        cin>>fa[i];
    }
    int cnt = 0;
    int k = n;
    while(k!=1)
    {
        cnt++;
        k = fa[k];
    }
    cout<<cnt<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}