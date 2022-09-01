#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forall(i, a) for(auto &i : a)

int mp[510][510];
int cnt[511][511];
void bye(int x,int y)
{
    cout<<x<<" "<<y<<endl;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    fr(i,1,n)
    {
        fr(j,1,m)
        {
            char c;
            cin>>c;
            if(c=='U')
            {
                mp[i][j] = 1;
            }
            else if(c=='D')
            {
                mp[i][j] = 2;
            }
            else if(c=='L')
                mp[i][j] = 3;
            else mp[i][j] = 4;
        }
    }
    int x = 1,y = 1;
    cnt[1][1] = 0;
    while(1)
    {
        cnt[x][y]++;
        if(cnt[x][y]>1)
        {
            cout<<"-1"<<endl;
            return ;
        }
        if(mp[x][y]==1)
        {
            if(x!=1)
            {
                x-=1;
            }
            else
            {
                bye(x,y);
                return ;
            }
        }
        if(mp[x][y]==2)
        {
            if(x!=n)
            {
                x++;
            }
            else
            {
                bye(x,y);
                return ;
            }
        }
        if(mp[x][y]==3)
        {
            if(y!=1)
            {
                y--;
            }
            else
            {
                bye(x,y);
                return;
            }
        }
        if(mp[x][y]==4)
        {
            if(y!=m)
            {
                y++;
            }
            else
            {
                bye(x,y);
                return;
            }
        }  
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}