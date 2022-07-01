#include<bits/stdc++.h>
using namespace std;
//字符串构造， 双指针

int n;
void solve()
{
    cin>>n;
    vector<int> a(n+1),b(a);
    vector<int> cnt(n+10);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    int i = n,j = n;
    for(int i=n;i>=1;i--)
    {
        while(j>1&&b[j]==b[j-1])
        {
            ++cnt[b[j]];
            --j;
        }
        if(j>=1 and a[i]==b[j]) --j;
        else if(cnt[a[i]]) --cnt[a[i]];
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}