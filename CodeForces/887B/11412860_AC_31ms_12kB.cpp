//#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>

int a[5][10];
int b[1010];
int vis[5];
int n,cnt;
void dfs(int p,int s)
{
	b[s] = 1;
	if(p>=n)
		return;
	for(int i = 1 ; i <= n ; i++)
	{
		if(vis[i])
			continue;
		for(int j = 1 ; j <= 6 ; j++)
		{
			vis[i] = 1;
			dfs(p+1,s*10+a[i][j]);
			vis[i] = 0;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,tmp;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ; i++)
		{
			for( j = 1 ; j <= 6 ; j++)
				scanf("%d",&a[i][j]);
		}
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		cnt = 0;
		dfs(0,0);
		for(int k = 1 ; k < 1000 ; k++)
		{
			if(!b[k])
			{
				tmp = k;
				break;
			}
		}
	
		printf("%d\n",tmp-1);
	}
	return 0;
}

