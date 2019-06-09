#include <stdio.h>
#include <string.h>
typedef _int64 ll;
const ll mod=1e9+7;
const int maxn = 100010;
int s[100],cnt[100];
int a[maxn];
int pri[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int dp[71][1<<19];

void init()
{
	int i,j;
	for( i = 2 ; i <= 70 ; i++)
	{
		int x = i;
		for( j = 0 ; j < 19 ; j++)
		{
			while(x%pri[j]==0)
			{
				s[i]^=(1<<j);
				x/=pri[j];
			}
		}
	}
	a[0]=1;
	for( i = 1 ; i <=100004 ; i++)
		a[i] = (2*a[i-1])%mod;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,x;
	init();
	while(~scanf("%d",&n))
	{
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		dp[0][0]=1;
		ll b = 1;
		for( i = 1 ; i <= 70 ; i++)
		{
			if(cnt[i]==0)
			{
				for( j = 0 ; j < (1<<19) ; j++)
				{
					dp[i][j] = dp[i-1][j];
				}
				continue;
			}
			for( j = 0 ; j < (1<<19) ; j++)
			{
				dp[i][j^s[i]]=b*(b*dp[i][j^s[i]]+b*dp[i-1][j]*a[cnt[i]-1])%mod;
				dp[i][j] = b*(b*dp[i][j]+b*dp[i-1][j]*a[cnt[i]-1])%mod;
			}
		}
		printf("%d\n",(dp[70][0]-1+mod)%mod);
	}
	return 0;
}