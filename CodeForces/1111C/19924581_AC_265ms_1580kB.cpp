#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 200010;
const int inf = 0x3ffffff;
typedef _int64 ll;
ll min(ll a,ll b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
ll a[maxn];
ll k,A,B;
ll dfs(ll l,ll r)
{
	ll posl = lower_bound(a,a+k,l)-a;
	ll posr = upper_bound(a,a+k,r)-a;
	posr--;
	ll x = posr-posl+1;
	if(l==r)
	{
		if(x!=0)
			return B*x;
		else
			return A;
	}
	if(x==0)
	{
		return A;
	}
	else
	{
		ll mid=(l+r)>>1;
		return min(B*x*(r-l+1),dfs(l,mid)+dfs(mid+1,r));
	}
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n;
	while(~scanf("%d%I64d%I64d%I64d",&n,&k,&A,&B))
	{
		for(int i = 0 ; i < k ; i++)
			scanf("%I64d",&a[i]);
		sort(a,a+k);
		ll l=1,r=ll(1)<<n;
		ll ans=dfs(l,r);
		printf("%I64d\n",ans);
	}
	return 0;
}