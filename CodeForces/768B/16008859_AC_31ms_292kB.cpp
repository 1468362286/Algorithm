#include <iostream>
#include <string>
typedef _int64 ll;

int query(ll n,ll L,ll R,ll l,ll r)
{
	if(R<l||L>r||n==0)
		return 0;
	if(n==1)
		return 1;
	ll mid=l+r>>1;
	return query(n/2,L,R,l,mid-1)+query(n%2,L,R,mid,mid)+query(n/2,L,R,mid+1,r);
}
int main()
{
	//freopen("in.txt","r",stdin);
	ll n,l,r;
	while(~scanf("%I64d%I64d%I64d",&n,&l,&r))
	{
		ll len = 1,x=n;
		while(x>1)
		{
			len=len*2+1;
			x>>=1;
		}
		printf("%d\n",query(n,l,r,1,len));
	}
	return 0;
}