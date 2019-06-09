#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
typedef _int64 ll;
ll a[maxn];
ll b[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		ll sum = 0;
		ll maxi=0,maxii=0;
		for( i = 0 ; i < n ; i++)
			scanf("%I64d",&a[i]),sum+=a[i];
		for( i = 0 ; i < n ; i++)
		{
			scanf("%I64d",&b[i]);
		}
		sort(b,b+n);
		if(sum>b[n-1]+b[n-2])
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}