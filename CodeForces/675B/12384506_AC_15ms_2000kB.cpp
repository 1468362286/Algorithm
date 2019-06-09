#include <stdio.h>
typedef _int64 ll;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,a,b,c,d;
	int y,z,w,m;
	while(~scanf("%d%d%d%d%d",&n,&a,&b,&c,&d))
	{
		ll cnt = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			y=i+b-c;
			z=i+a-d;
			w=a+y-d;
			if(y>=1&&y<=n&&z>=1&&z<=n&&w>=1&&w<=n)
			{
				cnt++;
			}
		}
		printf("%I64d\n",cnt*n);
	}
	return 0;
}