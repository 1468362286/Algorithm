#include <stdio.h>
#include <string.h>
double dp[11][11];
int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	double t;
	while(~scanf("%d%lf",&n,&t))
	{
		memset(dp,0,sizeof(dp));
		int ans = 0;
		dp[0][0]=t;
		for(int i = 0 ; i < n ;i++)
			for(int j = 0 ; j <= i ; j++)
			{
				if(dp[i][j]>=1.0)
				{
					dp[i+1][j]+=(dp[i][j]-1.0)/2;
					dp[i+1][j+1]+=(dp[i][j]-1.0)/2;
					ans++;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}