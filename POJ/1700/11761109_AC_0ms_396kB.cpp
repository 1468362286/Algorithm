#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int a[maxn];
int dp[maxn];
int min(int a,int b){return a>b?b:a;}

int main()
{
//	freopen("in.txt","r",stdin);
	int T,i,n;
	int ta,tb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for( i = 1 ; i <= n ; i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		dp[1]=a[1],dp[2]=a[2];
		for( i = 3 ; i <= n ; i++)
		{
			ta = dp[i-1]+a[i]+a[1];
			tb = dp[i-2]+a[1]+a[2]+a[i]+a[2];
			dp[i]=min(ta,tb);
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
