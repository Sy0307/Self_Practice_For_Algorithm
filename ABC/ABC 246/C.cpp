#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
using ll = long long;

ll a[200010];
priority_queue<ll> q;
int main()
{
    ios::sync_with_stdio(false);
    int n,k,x;
    long long total  = 0;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>a[i];
        int num = a[i]/x;
        num = min(num,k);
        if(k>0)
        {
            k-=num;
            a[i]-=num*x;
        }
        q.push(a[i]);
    }

    ll ans = 0;
    if(k==0)
    {
        while(q.size())
        {
            ans+=q.top();
            q.pop();
        }
        cout<<ans<<endl;
        return 0;
    }

    while(k&&q.size())
    {
        k--;
        q.pop();
    }
    while(q.size())
    {
        ans+=q.top();
        q.pop();
    }
    cout<<ans<<endl;
    return 0;
}