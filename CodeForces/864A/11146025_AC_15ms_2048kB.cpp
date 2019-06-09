#include <stdio.h>
#include <string.h>
#include <algorithm>
const int maxn = 110;
int a[maxn];
int b[2];
int hash[maxn],vist[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ; i++)
			scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		int aa=0,bb=0;
		for( i = 1 ; i <= n ; i++)
		{
			if(a[i]==a[1])
				aa++;
			else if(a[i]==a[n])
				bb++;
		}
		if(aa==n/2&&bb==n/2)
		{
			printf("YES\n%d %d\n",a[1],a[n]);
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}