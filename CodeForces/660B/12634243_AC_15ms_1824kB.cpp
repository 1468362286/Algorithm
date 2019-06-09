#include <stdio.h>
int rl[110],rr[110],ll[110],lr[110];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i;
	while(~scanf("%d%d",&n,&m))
	{
		int cnt=1;
		int p=1;
		while(1)
		{
			if(cnt<=n)
			{
				ll[cnt]=p++;
				rr[cnt]=p++;
				cnt++;
			}
			else
				break;
		}
		cnt=1;
		while(1)
		{
			if(cnt<=n)
			{
				lr[cnt]=p++;
				rl[cnt]=p++;
				cnt++;
			}
			else
				break;
		}
		cnt=1;
		for( i = 1 ; i <= n ; i++)
		{
			if(lr[i]>0&&lr[i]<=m)
			{
				printf(" %d",lr[i]);
			}
			if(ll[i]>0&&ll[i]<=m)
			{
				printf(" %d",ll[i]);
			}
			if(rl[i]>0&&rl[i]<=m)
			{
				printf(" %d",rl[i]);
			}
			if(rr[i]>0&&rr[i]<=m)
			{
				printf(" %d",rr[i]);
			}
		}
	//	printf("\n");
	}
	return 0;
}