#include <stdio.h>
const int maxn = 2010;
const int inf = 0x3f3f3f3f;
int a[maxn];

int gcd(int a,int b){return a==0?b:gcd(b%a,a);}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,l,r,tmp;
	while(~scanf("%d",&n))
	{
		int cnt = 0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)
				cnt++;
		}
		if(cnt!=0)
		{
			printf("%d\n",n-cnt);
			continue;
		}
		int mina = inf;
		for( i = 0 ; i < n ; i++)
		{
			tmp = a[i];
			for( j = i ; j < n ; j++)
			{
				tmp = gcd(a[j],tmp);
				if(tmp==1)
				{
					if(j-i<mina)
					{
						mina = j-i;
						l = i;
						r = j;
					}
				}
			}
		}
		if(mina!=inf)
		printf("%d\n",r-l+n-1);
		else
			printf("-1\n");
	}
	return 0;
}