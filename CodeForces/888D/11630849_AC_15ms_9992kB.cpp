#include <stdio.h>
typedef _int64 ll;

ll C[1010][1010];
void calc()
{
	for(int i = 0 ; i <= 1000 ; i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j = 1 ; j < i ; j++)
		{
			C[i][j] = C[i-1][j-1]+C[i-1][j];
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k;
	calc();
	while(~scanf("%d%d",&n,&k))
	{
		ll ans = 0;
		for(int i = n-1 ; i >=n-k ; i--)
		{
			if(i == n-1)
			{
				ans+=1;
			}
			else if(i==n-2)
			{
				ans+=C[n][i];
			}
			else if(i==n-3)
			{
				ans+=C[n][i]*2;
			}
			else if(i==n-4)
			{
				ans+=C[n][i]*9;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}