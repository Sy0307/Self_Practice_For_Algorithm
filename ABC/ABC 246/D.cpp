#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
using ll = long long ;
ll n,first;
bool check(int x)
{
        for(int i=first;i<=20+first;i++)
            for(int j=first;j<=i;j++)
            {
                ll tmp = i*i*i+i*i*j+j*j*i+pow(j,3);
                if(tmp>x) return false;
                if(tmp==x) return true;

            }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    first = (int)pow(n,0.2);
    bool f = 1;
    ll ans = n;
    while(f&&ans<=1000000000000000000)
    {
        if(check(ans))
        {
            cout<<ans<<endl;
            return 0;
        }
        ans++;
    }
    cout<<1000000000000000000<<endl;
    
    
    return 0;
}