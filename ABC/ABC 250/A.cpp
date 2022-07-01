#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int main()
{
    ios::sync_with_stdio(false);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans = 0;
    for(int i=0;i<4;i++)
    {
        int mx  = c+dx[i];
        int my = d+dy[i];
        if(mx>0&&my>0&&mx<=a&&my<=b)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}