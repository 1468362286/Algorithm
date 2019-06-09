#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,day;
	while(~scanf("%d",&n))
	{
		int maxi=0;
		int mina=0x7fffffff;
		for( i = 0 ; i < 7 ; i++)
		{
			int cnt = 0;
			for( j = 0 ; j < n ; j++)
			{
				day=(i+j)%7;
				if(day==5||day==6)
				{
					cnt++;
				}
			}
			if(cnt>maxi)
				maxi=cnt;
			if(cnt<mina)
				mina=cnt;
		}
		printf("%d %d\n",mina,maxi);
	}
	return 0;
}