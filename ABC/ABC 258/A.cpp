#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int h = t/60;
    t%=60;
    h+=21;
    if(t==0)
        cout<<h<<":00"<<endl;
    else if(t<10)
        cout<<h<<":0"<<t<<endl;
    else
        cout<<h<<":"<<t<<endl;
}