#include<bits/stdc++.h>
using  namespace std;


int in[200];
int n,m;
int main()
{
    cin>>n>>m;
    while(!(n==0&&m==0))
    {
        vector<int> need[202];
        memset(in,0,sizeof(in));
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            in[y]++;
            need[x].push_back(y);
        }
        bool vis[202]={0};
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
                vis[i]=1;
            }
        }
        while(q.size())
        {
            auto now = q.front();
            q.pop();
            cout<<now<<" ";
            for(auto &t:need[now])
            {
                if(--in[t]==0&&vis)
                {
                    q.push(t);
                }
            }
        }
        cin>>n>>m;
        cout<<endl;
    }

    return 0;

}