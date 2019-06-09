#include <stdio.h>

const int maxn = 100010;
int a[maxn];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,x,i;
	while(~scanf("%d%d",&n,&x))
	{
		int sum = 0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		/*
		if(n==1&&a[0]==0)
		{
			printf("YES\n");
		}
		*/
		if(x==sum+n-1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}