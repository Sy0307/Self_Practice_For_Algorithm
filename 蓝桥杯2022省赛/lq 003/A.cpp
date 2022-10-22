#include<bits/stdc++.h>
using namespace std;

struct line{
    int a;
    int at;
    int b;
    int bt;
    int c;
    int ct;
};
int n,k;
vector<line> edge;
using ll = long long;
int res = 0;
int remember[102][1010];
int dfs(int now,int step,int ans)
{
    if(step==k)  
    {
        return ans;
    }
    else if(remember[now][step]==0)
    {
        auto t = edge[now];
        int s1 = dfs(t.a,step+1,t.at);
        int s2 = dfs(t.b,step+1,t.bt);
        int s3 = dfs(t.c,step+1,t.ct);
        remember[now][step] = max(s1,max(s2,s3));
        return ans+remember[now][step];
    }
    else
    {
        return ans + remember[now][step];
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    edge.push_back({0,0,0,0,0,0});
    for(int i=1;i<=n;i++)
    {
        int t[7];
        for(int i=1;i<=6;i++)
            cin>>t[i];
        edge.push_back((line){t[1],t[2],t[3],t[4],t[5],t[6]});
    }
    for(int i=1;i<=n;i++)
    {
        res = 0;
        
        cout<<dfs(i,0,0)<<endl;
    }
    return 0;
}