#include<bits/stdc++.h>
using namespace std;
string make(string s,int n)
{
    string ans = s;
    ans+=(n+'0');
    ans+=s;
    return ans;
}
int a[100010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    int len = 1;
    a[1] = 1;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        a[len+1] = i;
        for(int j=len+2;j<=len*2+1;j++)
        {
            a[j] = a[j-len-1];
        }
        len = len*2+1;
    }
    for(int i=1;i<=len;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}