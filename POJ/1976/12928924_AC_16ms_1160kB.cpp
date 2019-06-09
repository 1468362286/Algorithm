#include <stdio.h>
#include <string.h>
const int maxn = 50010;
int dp[4][maxn];
int b[maxn];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int T,n,k,i,j,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&x);
			b[i]=b[i-1]+x;
		}
		scanf("%d",&k);
		memset(dp,0,sizeof(dp));		
		for( i = 1 ; i <= 3 ; i++)
			for( j = k ; j <= n ; j++)
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j-k]+b[j]-b[j-k]);
			}
		int ans=dp[3][n];
		printf("%d\n",ans);
	}
	return 0;
}
