#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef _int64 ll;
const int maxn = 200010;
int a[maxn];
ll min(ll a,ll b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < 2*n ; i++)
		{
			cin>>a[i];
		}
		sort(a,a+2*n);
		ll ans=ll(a[n-1]-a[i])*ll(a[2*n-1]-a[n]);
		for( i = 1 ; i <= n ; i++)
		{
			if(i==n)
				ans=min(ans,ll(a[i+n-1]-a[i])*ll(a[n-1]-a[0]));
			else
				ans=min(ans,ll(a[i+n-1]-a[i])*ll(a[2*n-1]-a[0]));
		}
		printf("%I64d\n",ans);
	}
	return 0;	
}