#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1') cnt++;
    }
    if(cnt&1||!cnt) 
    {
        cout<<"NO"<<endl;
        return ;
    }
    else cout<<"YES"<<endl;
    
    int now = -1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            now = i;
            break;
        }
    }
    int last = n;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='1')
        {
            last = i;
            break;
        }
    }
    auto pre = now;
    
    for(int i=now+1;i!=last;i++)
    {
        if(s[i]=='1')
        {
            cout<<pre+1<<" "<<i+1<<endl;
            pre = now;
        }
        else 
        {
            cout<<pre+1<<" "<<i+1<<endl;
            pre = i;
        }
    }
    
    int kk = (now - 1+n) %n;

    while(kk!=last - 1)
    {
        cout<<pre+1<<" "<<kk+1<<endl;
        pre = kk;
        kk = (kk+n - 1)%n;
    }
    



    
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>> T;
    while(T--)
    {
        solve();
    }
}