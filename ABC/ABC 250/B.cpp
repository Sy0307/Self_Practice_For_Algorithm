#include<bits/stdc++.h>
using namespace std;

string s1,s2;
void make(int x)
{
    for(int i=1;i<=x;i++)
        s1+='.';
    for(int i=1;i<=x;i++)
        s2+='#';
}
int main()
{
    ios::sync_with_stdio(false);

    int n,a,b;
    cin>>n>>a>>b;
    make(b);
    for(int i=1;i<=n;i++)
    {
        for(int k = 1;k<=a;k++)
        {
            for(int t = 1;t<=n;t++)
            {
                if((t+i)&1) cout<<s2;
                else cout<<s1; 
            }
            cout<<endl;
        }
    }
}