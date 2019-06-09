#include <stdio.h>
#include <queue>
using namespace std;
int max(int a,int b){return a>b?a:b;}

int a[1010];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i;
	_int64 k;
	while(~scanf("%d%I64d",&n,&k))
	{
		int maxi = 0;
		int count = 0;
		for( i = 1 ; i <= n ; i++)
			scanf("%d",&a[i]);
		maxi = a[1];
		if(k>=n)
		{
			printf("%d\n",n);
			continue;
		}
		for( i = 2 ; count < k ; i++)
		{
			if(maxi<a[i])
			{
				maxi = a[i];
				count=1;
			}
			else
				count++;
		}
		printf("%d\n",maxi);
	}
	return 0;
}