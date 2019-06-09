#include <stdio.h>
const int maxn = 1010;
int a[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",a+i);
		}
		int cnt = 0;
		for( i = 1 ; i < n-1 ; i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1])
				cnt++;
			else if(a[i]<a[i-1]&&a[i]<a[i+1])
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}