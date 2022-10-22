#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
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

int n;
void solve()
{
    cin>>n;
    vector<int> a(n);
    cin>>a;
    vector<int> dp(n,1);
    
    dp[0] = 1;
    fr(i,1,n)
    {
        for(int j = i-1;j>=0&&i - j<256;j--)
        {
            if((i^a[j])<(j^a[i]))
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    
    cout<<*max_element(dp.begin(),dp.end())<<endl;
    
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