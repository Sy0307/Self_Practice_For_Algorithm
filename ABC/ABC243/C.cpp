#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,y,d;

    bool operator<(const node&k) const
    {
        if(k.y==y) return k.x>x;
        else return k.y>y;
    }
}a[200010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
            a[i+1].d= -1;
        else a[i+1].d= +1;
    }
    sort(a+1,a+n+1);
    int index = -1;
    bool flag = 1;
    for(int i=1;i<=n;i++)
    {
        if(index==a[i].y)
        {
            if(a[i].d==-1&&flag)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
            else
            {
                if(a[i].d==1) flag = 1;
            }
        }
        else
        {
            index = a[i].y;
            flag =0;
            if(a[i].d==1)
                flag = 1;
        }
    }
    cout<<"No"<<endl;
    return 0;
}