#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
typedef _int64 ll;
const int maxn = 100010;
ll arr[maxn],dp[38][maxn],n;
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a>b?b:a;}
int solve(ll a,ll b,ll h, ll w)
{
	int i,j;
	int ans=-1;
	memset(dp,-1,sizeof(dp));
	dp[0][min(a,h)]=min(b,w);
	for( i = 1 ; i <= min(35,(int)n) ; i++)
	{
		for( j = 1; j <= a ; j++)
		{
			if(dp[i-1][j]==-1)continue;
			ll nx = min(a,j*arr[i]);
			ll ny = min(b,dp[i-1][j]*arr[i]);
			dp[i][j] = max(dp[i][j],ny);
			dp[i][nx] = max(dp[i][nx],dp[i-1][j]);
		}
	}
	for( i = 1 ; i < 36 ; i++)
		if(dp[i][a]>=b)
		{
			ans=i;
			break;
		}
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	ll a,b,h,w;
	int i;
	while(~scanf("%I64d%I64d%I64d%I64d%I64d",&a,&b,&h,&w,&n))
	{
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%I64d",&arr[i]);
		}
		if(h>=a&&w>=b||h>=b&&w>=a)
		{
			printf("0\n");
			continue;
		}
		sort(arr+1,arr+n+1,greater<ll>());
		int ans=min(solve(a,b,h,w),solve(a,b,w,h));
		if(ans==-1)puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}