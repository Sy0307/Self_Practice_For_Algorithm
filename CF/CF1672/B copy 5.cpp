#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        bool f = 1;
        int cnt = 0;
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]=='B')
            {
                cnt--;
                if(cnt<0) f=  0;
            }
            else cnt++;
        }
        if(s[s.size()-1]!='B') f= 0 ;
        if(f)
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }


}