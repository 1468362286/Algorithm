#include <stdio.h>
#include <string.h>
#include <math.h>
int n,a[107];
const int p = 1<<17;
int dp[107][p];
int pre[107][p];
int num[107][p];
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47,53};
int state[60];

void print(int i,int u)
{
	if(i==1)
	{
		printf("%d ",num[i][u]);
		return;
	}
	print(i-1,pre[i][u]);
	printf("%d ",num[i][u]);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ;i++)
		{
			scanf("%d",&a[i]);
		}
		memset(dp,0x3f,sizeof(dp));
		int INF = dp[0][0];
		dp[0][0] = 0;
		memset(state,0,sizeof(state));
		for( i = 2 ; i < 60 ; i++)
		{
			for( j = 0 ; j < 17 ; j++)
			{
				if(i%prime[j]==0)
				{
					state[i]|=(1<<j);
				}
			}
		}
		int total = 1<<17;
		for( i = 0 ; i < n; i++)
			for( j = 0 ; j < total ; j++)
			{
				if(dp[i][j]==INF)
					continue;
				for( k = 1 ; k < 59 ; k++)
				{
					if(state[k]&j)
						continue;
					int x = state[k]|j;
					if(dp[i+1][x]>dp[i][j]+abs(a[i+1]-k))
					{
						dp[i+1][x] = dp[i][j]+abs(a[i+1]-k);
						pre[i+1][x] = j;
						num[i+1][x] = k;
					}
				}
			}
		int ans = INF,loc=-1;
		for( i = 0 ; i < total ; i++)
			if(ans>dp[n][i])
			{
				ans = dp[n][i];
				loc = i;
			}
		print(n,loc);
		puts("");
	}
	return 0;
}