#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;

int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};
struct node{
    int x;int y;
    int dir;
};
bool vis[1510][1510];
bool mp[1510][1510];
int key[1510][1510];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    int sx,sy,ex,ey;
    memset(key,0x7f,sizeof(key));
    cin>>n;
    cin>>sx>>sy>>ex>>ey;
    vis[sx][sy] = 1;
    key[sx][sy] = 0;
    queue<node>q;
    int cnt = 0;
    q.push((node){sx,sy,10});
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        for(int j=1;j<=n;j++)
        {
            if(s[j-1]=='#')
            {
                mp[i][j] = 1;
                cnt++;
            }
        }
    }
  //  cout<<cnt<<endl;
    while(q.size())
    {
            auto t = q.front();
            q.pop();
            int x = t.x;
            int y = t.y;
            int step = key[x][y];
            int dir = t.dir;
      //     cout<<x<<" "<<y<<" "<<step<<endl;
      //      cout<<step<<endl;
            for(int i=0;i<4;i++)
            {

                int mx = x+dx[i];
                int my = y+dy[i];
                if(mx>0&&mx<=n&&my>=1&&my<=n&&!mp[mx][my])
                {
                    if(!vis[mx][my])
                    {
                        vis[mx][my] = 1;
                        int tmp = 0;
                        if(i!=dir) tmp = 1;
                    //     cout<<i<<endl;
                        
                        if(step+tmp<key[mx][my]) key[mx][my] = step+tmp;
                        if(mx==ex&&my==ey)
                        {
                            cout<<key[mx][my]<<endl;
                            return 0;
                        }
                        q.push((node){mx,my,i});
                    }
                }

                }
    }
    cout<<-1<<endl;
    
    return 0;
}