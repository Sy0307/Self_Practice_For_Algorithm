#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int kk = k;
    int nowpos = 0;
    bool suc = 0;
    int mx;
    while (1)
    {
        mx = 0;
        suc = 0;
        for (int i = nowpos + 1; i <= n && i - nowpos <= k; i++)
        {
            mx = max(a[i] , mx  - a[i]);
            if(mx<=p)
            {
                suc = 1;
                for(int j=nowpos+1;j<=i;j++)
                {
                    p+=a[j];
                }
                k = kk - (i - nowpos)+1;
                nowpos = i;
                break;
            }
        }
        if(suc==0)
        {
            cout<<"NO"<<endl;
            return ;
        }
        if(nowpos==n)
        {
            break;
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}