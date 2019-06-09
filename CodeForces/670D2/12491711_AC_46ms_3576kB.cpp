#include <stdio.h>
typedef _int64 ll;
ll a[100010],b[100010];
const int maxn=2*1e9+2;
ll n,k;

ll search(ll l,ll r)
{
	ll mid,sum;
	while(l<=r)
	{
		mid=(l+r)>>1;
		sum=0;
		for(int i = 0 ; i < n ; i++)
		{
			sum+=a[i]*mid-b[i]>0?a[i]*mid-b[i]:0;
			if(sum>k)
				break;
		}
		if(sum==k)
			return mid;
		else if(sum<k)
			l=mid+1;
		else
			r=mid-1;
	}
	return r;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%I64d%I64d",&n,&k))
	{
		for( i = 0 ; i < n ; i++)
			scanf("%I64d",&a[i]);
		for( i = 0 ; i < n ; i++)
			scanf("%I64d",&b[i]);
		printf("%I64d\n",search(1,maxn));
	}
	return 0;
}