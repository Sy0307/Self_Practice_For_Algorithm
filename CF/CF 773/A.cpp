#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        vector<pii> a(3);
        for(int i=0;i<3;i++)
        {
            cin>>a[i].second;
            cin>>a[i].first;
        }
        sort(a.begin(),a.end());
        if(a[1].first==a[2].first)
        {
            cout<<a[2].second- a[1].second<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}