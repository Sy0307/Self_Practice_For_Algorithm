#include<bits/stdc++.h>
using namespace std;


int s[4]={6,2,4,8};
int main()
{
    int n;
    cin>>n;
    int ans = 0;
    int now = n;
    while(now)
    {
        if(now%5==2)
        {
            ans++;
        }
        else if(now%5==4)
        {
            ans+=2;
        }
        ans+=now/5;
        now/=5;
    }
    if(n==1)
        cout<<1<<endl;
    else cout<<s[ans%4]<<endl;
}