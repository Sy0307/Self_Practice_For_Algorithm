#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    using ll = long long;
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];  
        k-=a[i];
        pq.push(a[i]);

    }
    if(k>0) pq.push(k);
 //   cout<<pq.top()<<endl;
//    ll a = 0;
    ll  ans = 0;
    while(pq.size()>1)
    {
        auto t1 = pq.top();
        pq.pop();
        auto t2 = pq.top();
        pq.pop();
        
        ans+=t1+t2;
        pq.push(t1+t2);
    }
    cout<<ans<<endl;
  //  else cout<<ans+k<<endl;

    return 0;
    
}