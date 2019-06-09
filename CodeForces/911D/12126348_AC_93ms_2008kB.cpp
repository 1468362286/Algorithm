#include <stdio.h>
const int maxn = 1510;
int a[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,m,l,r;
	while(~scanf("%d",&n))
	{
		int flag = 0;
		for( i = 1 ; i <= n ; i++)
			scanf("%d",&a[i]);
		int cnt = 0;
		for( i = 1 ; i <= n ; i++)
		{
			for( j = i+1 ; j <= n ; j++)
				if(a[i]>a[j])
				{
					cnt++;
				}
		}
		if(cnt%2==0)
			flag = 1;
		else
			flag = 2;
		scanf("%d",&m);
		for( i = 0 ; i < m ; i++)
		{
			scanf("%d%d",&l,&r);
			int d = r-l+1;
			int tmp = d*(d-1)/2;
			if(tmp%2==0)
			{
				printf("%s\n",flag==1?"even":"odd");
			}
			else
			{
				if(flag==1)flag=2;
				else if(flag==2)flag=1;
				printf("%s\n",flag==1?"even":"odd");
			}
		}
	}
	return 0;
}
