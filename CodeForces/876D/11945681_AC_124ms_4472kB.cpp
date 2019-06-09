#include <stdio.h>
const int maxn = 300010;
int a[maxn],b[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,x;
	while(~scanf("%d",&n))
	{
		int cnt = 1;
		int last = 0;
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&x);
			a[x] = 1;
			for( j = n-last ; j > 0 ;j--)
			{
				if(a[j]==1)
				{
					last++;
				}
				else if(a[j]==0)
					break;
			}
			b[cnt++]=i-last;
		}
		printf("%d",b[0]+1);
		for( i = 1 ; i < n+1 ; i++)
			printf(" %d",b[i]+1);
		printf("\n");
	}
	return 0;
}