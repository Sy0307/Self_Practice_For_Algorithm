#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 200000;
const long long  INF = (ll)1e+18;
using pll = pair<ll,ll>;
int main()
{
    ios::sync_with_stdio(false);
    int n,m,k,l;
    int x,y,sz;
    ll z;
    cin>>n>>m>>k>>l;
    vector<int> a(n);
    vector<vector<pair<int,ll>>> e(n);

    vector<int>used(n, 0);
	vector<ll>d(n, INF);
	vector<int>cit(n);
	vector<ll>dd(n, INF);

    priority_queue<tuple<ll,int,int>> pq;
    tuple <ll,int,int > t;

    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<l;i++)
    {
        cin>>x;
        pq.push({0LL,x-1,a[x-1]});
    }
    for(int i=0;i<m;++i)
    {
        cin>>x>>y>>z;
        e[x-1].push_back({y-1,z});
        e[y-1].push_back({x-1,z});
    }
    while(pq.size())
    {
        t = pq.top();
        pq.pop();
        z = get<0>(t);
        x = get<1>(t);
        y = get<2>(t);

        if(used[x]>=0 and used[x]!=y)
        {
            if(used[x]==0)
            {
                d[x] = -z;
                cit[x] = y;
                used[x] = y;
            }
            else
            {
                dd[x] = -z;
                used[x] = -1;
            }

            sz = e[x].size();
            for(int i=0;i<sz;i++)
                pq.push({ z - e[x][i].second,e[x][i].first,y });
        }
    }

    for(int i=0;i<n;i++)
    {
        if(d[i]>=INF) d[i] = -1;
        if(dd[i]>=INF) dd[i] = -1;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=cit[i]) cout<<d[i];
        else cout<<dd[i];
        if(i<(n-1)) cout<<" ";
        else cout<<endl;
    }
    return  0;

}