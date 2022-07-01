#include<bits/stdc++.h>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x = 0;
    int y = 0;
    int t = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='S')
        {
            x+=dx[t];y+=dy[t];
        }
        else
        {
            t++;
            if(t==4) t = 0;
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}