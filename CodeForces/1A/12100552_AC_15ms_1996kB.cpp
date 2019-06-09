#include <stdio.h>
typedef _int64 ll;
int main()
{
	int n,m,a;
	ll l,r;
	while(~scanf("%d%d%d",&n,&m,&a))
	{
		if(n%a!=0)
			l = n/a+1;
		else
			l = n/a;
		if(m%a!=0)
			r = m/a+1;
		else
			r = m/a;
		printf("%I64d\n",l*r);
	}
	return 0;
}