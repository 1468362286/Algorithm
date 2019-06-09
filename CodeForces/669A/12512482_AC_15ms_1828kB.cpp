#include <stdio.h>

int a[3];
int main()
{
	int n;
	a[1]=1,a[2]=1,a[3]=2;
	while(~scanf("%d",&n))
	{
		printf("%d\n",(n/3)*2+a[n%3]);
	}
	return 0;
}