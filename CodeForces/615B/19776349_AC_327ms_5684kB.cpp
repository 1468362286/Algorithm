#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 100010;
const int inf = 0x3ffffff;
typedef _int64 ll;
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}
vector<int>vec[maxn];
ll dp[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,m,i,j,u,v;
	while(cin>>n>>m)
	{
		for( i = 0 ; i < m ; i++)
		{
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		ll ans=-1;
		for( i = 1 ; i <= n ; i++)
		{
			dp[i]=1;
			for( j = 0 ; j < vec[i].size() ; j++)
			{
				int to = vec[i][j];
				if(to<i)
				{
					dp[i]=max(dp[i],dp[to]+1);
				}
			}
			ans=max(ans,dp[i]*(ll)vec[i].size());
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
