#include <stdio.h>
typedef _int64 ll;
int main()
{
	//freopen("in.txt","r",stdin);
	ll x,y,l,r,k,i,j;
	while(~scanf("%I64d%I64d%I64d%I64d%I64d",&l,&r,&x,&y,&k))
	{
		int flag = 0;
		for( i = x ; i <= y ; i++)
			if(i*k>=l&&k*i<=r)
			{
				flag=1;
				break;
			}
			printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}