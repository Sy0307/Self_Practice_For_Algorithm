#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
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


bool check(int x)
{
    fr(i,2,sqrt(x))
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int n;
    cin>>n;
    if(check(n))
    {
        cout<<1<<endl;
    }
    else if(n%2==0)
    {
        cout<<2<<endl;
    }
    else if(check(n-2))
    {
        cout<<2<<endl;
    }
    else
    {
        cout<<3<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}