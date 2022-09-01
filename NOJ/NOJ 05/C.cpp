#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxn  = 1e6 +10;
void solve()
{
    int n;
    cin>>n;
    int x = 0;
    vector<int> a(maxn, 0);
    for(int i = 2;i<=n;i++)
    {
        for(int j = 2;j*i< maxn ;j++)
        {
            a[j*i] = -1;
        }
    }
    for(int i  =2;i<=n;i++)
    {
        if(a[i] == 0)
        {
            a[i] = ++x;
        }
    }

    for(int i = 2;i<=n;i++)
    {
        if(a[i] == -1)
        {
            int t = i;
            for(int j  =2;j*j<=i;j++)
            {
                if(i%j == 0)
                {
                    a[i] = a[j];
                    break;
                }
            }
        }
    }
    for(int i = 2;i<=n;i++)
    {
        cout<<a[i]<<(i==n?'\n':' ');
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int T =1 ;
    while (T--)
    {
        solve();
    }
    return 0;
}