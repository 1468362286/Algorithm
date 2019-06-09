#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 110;
int a[110];
int max(int a,int b){return a>b?a:b;}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i,j;
	while(~scanf("%d%d",&n,&k))
	{
		int ans = 0;
		for( i = 0 ; i < n ; i++)
			scanf("%d",a+i);
		sort(a,a+n);
		for( i = 0 ; i < n ; i++)
			for( j = i+1 ; j < n ; j++)
			{
				if(a[j]-a[i]<=k)
					ans=max(ans,j-i+1);
			}
		if(n==1)
		{
			printf("0\n");
		}
		else if(ans==0)
			printf("%d\n",n-1);
		else
		printf("%d\n",n-ans);
	}
	return 0;
}