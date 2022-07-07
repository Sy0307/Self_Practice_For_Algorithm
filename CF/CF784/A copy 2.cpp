#include<bits/stdc++.h>
using namespace std;

char ss[110][1010]; 
deque<char> kk;
vector<char> ans;
int tick[1010]={0};
int main()
{

    ios::sync_with_stdio(0);
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>ss[i][j];
        }
    
    }
    for(int i=1;i<=n;i++)
        tick[i] = 1;
    int x;
    cin>>x;
 //   cout<<kk.size()<<endl;
    while(1)
    {
        if(ans.size()) cout<<ans.back()<<endl;
        if(x==-1)
        {
            for(auto &t:ans)
            {
                cout<<t;
            }
            return 0;
        }
        if(x==0)
        {
            if(ans.size())
            {
            //    cout<<kk.size()<<endl;
                auto now = kk.back();
                kk.pop_back();
                ans.push_back(now);
            }
        }
        else 
        {
            if(tick[x]>m) continue;
        //    if(kk.empty()) continue;
            if(kk.size()==s)
            {
                auto now = kk.back();
                ans.push_back(now);
                kk.pop_back();
                now = ss[x][tick[x]];
                tick[x]++;
                kk.push_back(now);
                
            }
            else
            {
                auto now = ss[x][tick[x]];
                tick[x]++;
                kk.push_back(now);
            }

        }
        cin>>x;

    }
    return 0;
    
}