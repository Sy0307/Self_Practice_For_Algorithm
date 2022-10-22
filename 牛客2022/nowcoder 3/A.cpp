#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end(),[](const string &a,const string &b){
        return (a+b)<(b+a);
    });
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
}