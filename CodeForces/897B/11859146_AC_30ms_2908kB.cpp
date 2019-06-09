#include <stdio.h>
#include <string.h>
typedef _int64 ll;
const int maxn = 100010;
ll a[maxn];
int b[10];

void init()
{
	ll tmp = 0;
	for(int i = 1 ; i <= 100000 ; i++)
	{
		int pp = i;
		int cnt = 0;
		memset(b,0,sizeof(b));
		while(pp)
		{
			b[cnt++] = pp%10;
			pp/=10;
		}
		ll ans = 0;
		ll tmp = i;
		for(int j = 0 ; j < cnt ; j++)
			ans = ans*10+b[j];
		for(int k = 0 ; k < cnt ; k++)
		tmp =tmp*10;
		tmp+=ans;
		a[i] = a[i-1]+tmp;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int k,p;
	init();
	while(~scanf("%d%d",&k,&p))
	{
		printf("%I64d\n",a[k]%p);
	}
	return 0;
}