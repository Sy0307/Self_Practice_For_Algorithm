#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod = 998244353;
const int maxn = 2e6+10;
int seed;
int n,q;
struct company{
    int iq,eq,aq;
}a[maxn];
void pre()
{
    cin>>n>>q;
    
    cin>>seed;
}
void solve()
{
    std::mt19937 rng(seed);
    std::uniform_int_distribution<> u(1, 400);
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        pre();
        solve();
    }
    return 0;
}