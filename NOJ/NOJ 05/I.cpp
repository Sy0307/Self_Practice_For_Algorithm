#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n, 0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    int ans = 0x3f3f3f3f;
    int cur = a.back()/3;
    for(int f1 = 0;f1<=2;f1++)
    {
        for(int f2 = 0;f2<=2;f2++)
        {
            for(int f3 =max(cur-2,0);f3<=cur;f3++)
            {
                int tot = f1+f2+f3;
                if(tot>=ans) continue;
                bool kk = 1;
                for(auto now:a)
                {
                    bool f = 0;
                    for(int i=0;i<=f1;i++)
                    {
                        for(int j = 0;j<=f2;j++)
                        {
                            ll rest = now-i-j*2;
                            if(rest>=0&&rest%3==0&&rest/3<=f3)
                            {
                                f = 1;
                                break;
                            }

                        }
                    }

                    if(!f)
                    {
                        kk = 0;
                        break;
                    }
                }
                if(kk)
                {
                    ans = min(ans,tot);
                  //  cout<<f1<<" "<<f2<<" "<<f3<<endl;
                }
            }
        }
    }
    cout<<ans<<endl;
    
    
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