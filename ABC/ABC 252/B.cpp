#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    int kk = -1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        kk = max(kk,a[i]);
    }
    set<int> s;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==kk)
        {
            if(s.find(i)!=s.end())
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
    
    
}