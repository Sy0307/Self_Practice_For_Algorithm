#include<bits/stdc++.h>
#define For(i,j) for(int i=1;i<=j;i++)
using namespace std;

bool mp[2010][2010];
int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int total = 0;
        For(i,n)
        {
            string s;
            cin>>s;
            For(j,n)
            {
                if(s[j-1]=='1') mp[i][j] = 1;
                else mp[i][j] = 0;
                total +=mp[i][j]; 
            }
        }
    //    cout<<total<<endl;
        int ans = INT_MAX;
        int x = 1,y = 1;
        For(i,n)
        {
            x = i; y =1;
            int pick = 0;
            int cnt = 0;
            while(cnt<n)
            {
                if(mp[x][y])
                    pick++;
            //    cout<<x<<y<<endl;
                x++;
                if(x>n) x = 1;
                y++;
                cnt++;
            }
            ans  = min(ans,total - pick + n-pick);
        }
        cout<<ans<<endl;
        
        
        
    }
    return 0;
}