#include <iostream>
#include <string>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef _int64 ll;
const int maxn = 1010;
int a[maxn],b[maxn];
ll c[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k1,k2,i;
	while(cin>>n>>k1>>k2)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		for( i = 0 ; i < n ; i++)
			cin>>b[i];
		for( i = 0 ; i < n ; i++)
		{
			c[i]=abs(a[i]-b[i]);
		}
		sort(c,c+n);
	/*	for( i = 0 ; i < n ; i++)
			printf("%d ",c[i]);
		printf("\n");*/
		int k=k1+k2;
		for( i = 0 ; i < k ; i++)
		{
			if(c[n-1]==0)
				c[n-1]++;
			else
				c[n-1]--;
			sort(c,c+n);
		}
		ll ans=0;
		for( i = 0 ; i < n ; i++)
		{
			ans+=(c[i]*c[i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}