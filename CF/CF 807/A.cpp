#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int INF = 0x3f3f3f3f;
using ll = long long;
char s[maxn];
ll l[100],r[100];
ll sum[100];
void solve()
{
    int n,c,q;
    cin>>n>>c>>q>>s+1;
    sum[0] = n;
    for(int i=1;i<=c;i++)
    {
        cin>>l[i]>>r[i];
        sum[i] = sum[i-1] - l[i] + r[i] +1;
    }

    while(q--)
    {
        ll k;
        cin>>k;
        for(int i=c;i>=1;i--)
        {
            if(k>sum[i-1]&&k<=sum[i])
            {
                k = l[i] +k  - sum[i-1] - 1;
            }
        }
        cout<<s[k]<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}