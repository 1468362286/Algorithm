#include <stdio.h>
int a[1000000];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,ans,tmp;
	while(~scanf("%d",&n))
	{
		int cnt = 0;
		int pp = 0;
		tmp = n;
		while(tmp)
		{
			tmp/=10;
			pp++;
		}
		for( i = n-9*pp ; i <= n ; i++)
		{
			ans = i;
			tmp = i;
			while(tmp)
			{
				ans+=tmp%10;
				tmp/=10;
			}
			if(ans==n)
			{
				a[cnt++] = i;
			}
		}
		if(cnt==0)
			printf("0\n");
		else
		{
			printf("%d\n",cnt);
			printf("%d",a[0]);
			for( i = 1 ; i < cnt ; i++)
				printf(" %d",a[i]);
			printf("\n");
		}
	}
	return 0;
}