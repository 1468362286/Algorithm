#include <stdio.h>
#include <string.h>
const int maxn = 110;
int vist[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j,x,y;
	while(~scanf("%d%d",&n,&m))
	{
		memset(vist,0,sizeof(vist));
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d%d",&x,&y);
			for( j = x+1 ; j <= y ; j++)
			{
				vist[j] = 1;
			}
		}
		int flag = 0;
		for( i = 1 ; i <= m ; i++)
		{
			if(vist[i]==0)
			{
				flag = 1;
				break;
			}
		}
		if(flag)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}