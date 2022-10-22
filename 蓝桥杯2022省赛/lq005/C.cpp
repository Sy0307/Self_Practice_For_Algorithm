#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[1000010];
int main()
{
    ios::sync_with_stdio(false);
    ll n,k;
    int cnt = 0;
    cin>>n>>k;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            a[++cnt] = i;
        }
    }
 //   cout<<cnt<<endl;
    int now = 0;
    if(a[cnt]*a[cnt]==n)
        now =1;
 //   cout<<now<<endl;
    if(2*cnt+now<k)
    {
        cout<<-1<<endl;
    }
    else
    {
        if(k<=cnt)
        {
            cout<<a[k]<<endl;
            return 0;
        }
        k-=cnt;
       // cout<<k<<endl;
        cout<<n/a[cnt-k+1-now]<<endl;
    }

    return 0;
}