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

void solve()
{
    int n;
    cin>>n;
    int a = 0,b = 0;
    fr(i,1,n-2)
    {
        a^=(i-1);
        b^=i;
    }
    ll last = ((ll)1<<31) - 1;
    if(a!=0)
    {
        fr(i,0,n-3)
        {
            cout<<i<<" ";
        }
        a^=last;
        cout<<last<<" "<<a<<endl;
    }
    else
    {
        fr(i,0,n-3)
        {
            cout<<i+1<<" ";
        } 
        b^=last;
        cout<<last<<" "<<b<<endl;
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