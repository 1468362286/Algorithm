#include <stdio.h>
#include <string.h>
const int maxn = 550;
int a[maxn];
bool dp[maxn][maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i,j,l;
	while(~scanf("%d%d",&n,&k))
	{
		for( i = 1 ; i <= n ; i++)
			scanf("%d",&a[i]);
		memset(dp,false,sizeof(dp));
		dp[0][0]=1;
		for( i = 1 ; i <= n ; i++)
		{
			for( j = k ; j >= a[i] ; j--)
			{
				for( l = 0 ; l <= k-a[i] ; ++l)
				{
					if(dp[j-a[i]][l])
						dp[j][l]=dp[j][l+a[i]]=1;
				}
			}
		}
		int cnt=0;
		for( i = 0 ; i <= k ; i++)
			if(dp[k][i])
			{
				cnt++;
			}
		printf("%d\n",cnt);
		for( i = 0 ; i <= k ; i++)
			if(dp[k][i])
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}