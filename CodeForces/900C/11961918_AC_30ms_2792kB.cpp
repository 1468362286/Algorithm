#include <stdio.h>
const int maxn = 100010;
int a[maxn];
int c[maxn];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		int p = 0,q=0;
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",a+i);
		}
		for( i = 1 ; i <= n; i++)
		{
			if(a[p]<a[i])
			{
				q = p;
				p = i;
				c[p]--;
			}
			else if(a[q]<a[i])
			{
				q = i;
				c[p]++;
			}
		}
		int k = 1;
		for( i = 1 ; i <= n ; i++)
		{
			if(c[i]>c[k]||c[i]==c[k]&&a[i]<a[k])
			{
				k = i;
			}
		}
		printf("%d",a[k]);
	}
	return 0;
}