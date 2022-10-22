#include<bits/stdc++.h>
#define maxn 50500
using namespace std;
int n,m,cnt,del;
int ans[maxn],start[maxn],to[maxn],cur[maxn];
vector<int> v[maxn];

inline bool check() {
	if(cnt != n) return false;
	for(int i=1;i<=n;i++) if(cur[i]!=ans[i]) return ans[i]>cur[i];
}
void dfs(int u,int f) {
	if(cnt>n) return ;
	cur[++cnt]=u;
	for(int i=0;i<v[u].size();i++) {
		if(v[u][i]==f || (u==start[del]&&v[u][i]==to[del]) || (v[u][i]==start[del]&&u==to[del])) continue;
		dfs(v[u][i],u);
	}
}
int main() {
    ios::sync_with_stdio(false);
	memset(ans,64,sizeof(ans));
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
        int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		start[i]=x;to[i]=y;
	}
	
	for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
    del=0;cnt=0;
    dfs(1,0);
    memcpy(ans,cur,sizeof(cur));

	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
