#include <stdio.h>

int res[10][2];
int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b,c,n;
	while(~scanf("%d",&n))
	{
		a=b=c=0;
		for( i = 0 ; i < 10 ; i++)
			for( j = 0 ; j < 2 ; j++)
				res[i][j] = j;
		for( i = 0 ; i < n ; i++)
		{
			static char s[5];
			scanf("%s",s);
			int x;
			scanf("%d",&x);
			for( j = 0 ; j < 10 ; j++)
				for( k  = 0 ; k < 2 ; k++)
				{
					if(s[0]=='&')
						res[j][k]&=(x>>j&1);
					if(s[0]=='|')
						res[j][k]|=(x>>j&1);
					if(s[0]=='^')
						res[j][k]^=(x>>j&1);
				}
		}
		for( i = 0 ; i < 10 ; i++)
		{
			if(res[i][0]!=res[i][1])
			{
				a^=1<<i;
				if(!res[i][0])
				{
					c^=1<<i;
				}
			}
			else
			{
				b^=1<<i;
				if(!res[i][0])
				{
					c^=1<<i;
				}
			}
		}
		printf("3\n");
		printf("^ %d\n",a);
		printf("| %d\n",b);
		printf("^ %d\n",c);
	}
	return 0;
}