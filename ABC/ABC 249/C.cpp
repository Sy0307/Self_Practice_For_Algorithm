#include<bits/stdc++.h>
using namespace std;

int n,k;
int dfs(vector<string> &a ,vector<string> choose, int pos)
{
    if(pos==a.size())
    {
        map<char,int> cnt; 
        for(auto &it:choose)
        {
            for(int i=0;i<it.size();i++)
            {
                cnt[it[i]]++;
            }
        }
        int res = 0;
        for(auto &it:cnt)
        {
            if(it.second==k)
            {
                res++;
            }
        }
        return res;
    }
    int a1 = dfs(a,choose,pos+1);
    choose.push_back(a[pos]);
    int a2 = dfs(a,choose,pos+1);
    return max(a1,a2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    vector<string> str(n);
    vector<string>choose;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    cout<<dfs(str,choose,0)<<endl;
    
    

}