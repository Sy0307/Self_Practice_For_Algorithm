#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
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
    cin >> n;
    vector<int> a(n + 1);
    int cnt = 0;
    fr(i, 1, n)
    {
        cin >> a[i];
        if (a[i] & 1)
        {
            cnt++;
        }
    }
    if (cnt & 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        else if (a[i] & 1)
        {
            a[i] = 1;
        }
        else
            a[i] = 2;
    }
    if(a[1]==2) a[1] = 0;
    fr(i, 2, n)
    {
        if (a[i] == 0)
            continue;
        if (a[i - 1] == 1)
        {
            a[i]--;
            a[i-1]--;
        }
        else if(a[i]==2)
        {
            a[i] = 0 ;
        }
    }
    fr(i,1,n)
    {
        if(a[i])
        {
            // cout<<i<<endl;
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}