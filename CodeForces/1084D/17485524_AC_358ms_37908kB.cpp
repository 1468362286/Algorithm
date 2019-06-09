#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef _int64 ll;
const int maxn = 300010;
const int inf = 0x3f3f3f3f;
ll dp[maxn];
vector<pair<int,ll> >vec[maxn];
ll w[maxn];
ll ans;
ll max(ll a,ll b){return a>b?a:b;}
void dfs(int u,int fa)
{
	dp[u]=w[u];
	ans=max(ans,dp[u]);
	for(int i = 0 ; i < vec[u].size() ; i++)
	{
		int to = vec[u][i].first;
		ll val = vec[u][i].second;
		if(to==fa)continue;
		dfs(to,u);
		ans=max(ans,dp[to]+dp[u]-val);
		dp[u] = max(dp[u],w[u]+dp[to]-val);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int u,v,i,n;
	ll x;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			scanf("%I64d",&w[i]);
		for( i = 1 ; i < n ; i++)
		{
			scanf("%d%d%I64d",&u,&v,&x);
			vec[u].push_back(make_pair(v,x));
			vec[v].push_back(make_pair(u,x));
		}
		ans=0;
		dfs(1,0);
		printf("%I64d\n",ans);
	}
	return 0;
}