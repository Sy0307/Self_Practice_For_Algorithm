#include<bits/stdc++.h>
using namespace std;

char a[3],b[3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>b[i];
    }
    int diff = 0;
    for(int i=0;i<3;i++)
        if(a[i]!=b[i]) diff++;
    if(diff==0) cout<<"Yes"<<endl;
    else if(diff==3) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}