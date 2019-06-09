#include <stdio.h>
typedef _int64 ll;
int main()
{
	int n;
	ll x,tmp;
	char ch[2];
	while(~scanf("%d%I64d",&n,&x))
	{
		int cnt = 0;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%s%I64d",&ch,&tmp);
			if(ch[0]=='+')
			{
				x+=tmp;
			}
			else if(ch[0]=='-')
			{
				if(x-tmp<0)
				{
					cnt++;
				}
				else
				{
					x-=tmp;
				}
			}
		}
		printf("%I64d %d\n",x,cnt);
	}
	return 0;
}