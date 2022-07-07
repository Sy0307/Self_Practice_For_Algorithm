#include<bits/stdc++.h>
using namespace std;

bool judge()
{
    int n;
    cin>>n;
    int a[1010];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n>=3)
    for(int i=3;i<=n;i+=2)
    {
        if(a[i]!=a[i-2]) return false;
    }
    if(n>=4)
    {
        for(int i=4;i<=n;i+=2)
        {
            if(a[i]!=a[i-2]) return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        if(judge())
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}