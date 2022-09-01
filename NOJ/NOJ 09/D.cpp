#include<iostream>
#include<cstdio>
using namespace std;
// using ui = unsigned int;
// using ull = unsigned long long;
// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// #define fr(i, a, b) for (int i = a; i <= b; i++)
// #define ford(i, a, b) for (int i = a; i >= b; i--)
// #define forall(i, a) for (auto &i : a)

void solve(int n,int k)
{
    if((n&k)==k)
    {
        cout<<1<<endl;
    }
    else cout<<0<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int T = 1;
    // cin >> T;
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        solve(n,m);
    }
    return 0;
}