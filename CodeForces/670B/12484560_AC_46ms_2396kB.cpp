#include <stdio.h>
typedef _int64 ll;
int a[100010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	ll ans,k;
	while(~scanf("%d%I64d",&n,&k))
	{
		for( i = 0 ; i < n ; i++)
			scanf("%d",a+i);
		for(ll j = 1 ;  ; j++)
			if((1+j)*j>=2*k)
			{
				ans = j-1;
				break;
			}
		k-=(1+ans)*ans/2;
		printf("%d\n",a[int(k-1)]);
	}
	return 0;
}