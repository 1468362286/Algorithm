#include <stdio.h>
#include <math.h>
typedef _int64 ll;

int main()
{
	//freopen("in.txt","r",stdin);
	ll m,n;
	while(~scanf("%I64d%I64d",&n,&m))
	{
		if(n>=32)
		{
			printf("%I64d\n",m);
			continue;
		}
		ll ans = 1<<n;
		ans = m%ans;
		printf("%I64d\n",ans);
	}
	return 0;
}