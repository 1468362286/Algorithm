#include <stdio.h>
const int maxn = 110;
int a[maxn];
int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		for( i = 0 ; i < n ; i++)
			scanf("%d",a+i);
		if(a[0]%2==0||a[n-1]%2==0||n%2==0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}