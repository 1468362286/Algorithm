#include <stdio.h>
#include <algorithm>
using namespace std;
int a[20010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ; i++)
			scanf("%d",a+i);
		int flag=1;
		while(flag)
		{
			for( i = 1 ; i < n ; i++)
			{
				if(a[i]>a[i+1])
				{
					swap(a[i],a[i+1]);
					printf("%d %d\n",i,i+1);
				}
			}
			int cnt=0;
			for( i = 1 ; i < n; i++)
				if(a[i]<=a[i+1])
				{
					cnt++;
				}
			if(cnt==n-1)
				flag=0;
		}
	}
	return 0;
}