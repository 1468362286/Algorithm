#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 300010;
typedef _int64 ll;
ll a[4][maxn];
ll sum[4][maxn];
ll num[4];
ll max(ll a,ll b){return a>b?a:b;}
struct node
{
	ll v;
	ll num1,num2;
}dp[maxn];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j;
	while(~scanf("%d%d",&n,&m))
	{
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));
		for( i = 1 ; i <= n ; i++)
		{
			ll x,y;
			scanf("%I64d%I64d",&x,&y);
			a[x][++num[x]]=y;
		}
		for( i = 1 ; i <= 3 ; i++)
		{
			sort(a[i]+1,a[i]+num[i]+1,cmp);
			for( j = 1 ; j <= num[i] ; j++)
			{
				sum[i][j]=sum[i][j-1]+a[i][j];
			}
		}
		dp[0].num1=dp[0].num2=dp[0].v=0;
		for( i = 1 ; i <= m ; i++)
		{
			dp[i]=dp[i-1];
			if(dp[i].v<dp[i-1].v+a[1][dp[i-1].num1+1])
			{
				dp[i].v=dp[i-1].v+a[1][dp[i-1].num1+1];
				dp[i].num2=dp[i-1].num2;
				dp[i].num1=dp[i-1].num1+1;
			}
			if(i>=2&&dp[i].v<dp[i-2].v+a[2][dp[i-2].num2+1])
			{
				dp[i].v=dp[i-2].v+a[2][dp[i-2].num2+1];
				dp[i].num2=dp[i-2].num2+1;
				dp[i].num1=dp[i-2].num1;
			}
		}
	//	printf("%I64d:",dp[m].v);
		ll res=0;
		for( i = 0 ; i <= num[3] ; i++)
		{
			if(m>=i*3)
			{
				res=max(res,max(dp[m-i*3].v+sum[3][i],dp[m].v));
			}
		}
		printf("%I64d\n",res);
	}
	return 0;
}