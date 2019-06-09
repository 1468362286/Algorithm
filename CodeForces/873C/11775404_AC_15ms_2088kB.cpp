#include <stdio.h>
int map[150][150];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,k,i,j,l;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for( i = 1 ; i <= n ; i++)
			for( j = 1 ; j <= m ; j++)
				scanf("%d",&map[i][j]);
		int ans1 = 0,ans2=0;
		for( j = 1 ; j <= m ; j++)
		{
			int pre = 0;
			int maxn = 0;
			int del = 0;
			for( i = 1 ; i <= n ; i++)
			{
				int cnt = 0;
				for( l = i ; l <= n&&l-i+1<=k ; l++)
				{
					if(map[l][j]==1)
						cnt++;
				}
				if(maxn<cnt)
				{
					maxn = cnt;
					del = pre;
				}
				pre+=map[i][j];
			}
			ans1+=maxn;
			ans2+=del;
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
