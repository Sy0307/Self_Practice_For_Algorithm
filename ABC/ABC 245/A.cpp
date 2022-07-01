#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int k = (a-c)*60;
    int t = (b-d);
    if(k+t<=0) 
    {
        cout<<"Takahashi"<<endl;
    }
    else cout<<"Aoki"<<endl;

    return 0;
}