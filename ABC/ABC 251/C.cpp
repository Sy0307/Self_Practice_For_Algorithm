#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;cin>>n;
    int val = 0;
    int anspos = 0;
    map<string,int> mp;
    for(int i=1;i<=n;i++)
    {
        string tmp;
        int x;
        cin>>tmp>>x;
        if(mp[tmp]==0)
        {
            if(x>val)
            {
                val = x;
                anspos = i;
            }
            mp[tmp] = x;
        }
    }
    cout<<anspos<<endl;
    return 0;
}