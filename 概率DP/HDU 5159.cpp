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


void solve(int num)
{
    double x,b;
    cin>>x>>b;
    double sum = (x+1)*x / 2;
    double tmp = 1 - pow(1 - 1.0/x,b);
    cout<<"Case #"<<num<<": ";
    cout<<sum*tmp<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    fr(i,1,T)
    {
        solve(i);
    }
    return 0;
}