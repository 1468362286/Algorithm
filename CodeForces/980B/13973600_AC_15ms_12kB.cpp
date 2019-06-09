#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
int p[5][101];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i,j;
	while(~scanf("%d%d",&n,&k))	
	{
		memset(p,0,sizeof(p));
		int tmp=0;
		if(k%2!=0)
		{
			tmp=k;
			k--;
		}
		if(k>0)
		{
			for( i = 2 ; i <= n/2 ; i++)
			{
				p[2][i]=1;
				p[2][n-i+1]=1;
				k-=2;
				if(k==0)
					break;
			}
			if(k>0)
			{
				for( i = 2 ; i <= n/2 ; i++)
				{
					p[3][i]=1;
					p[3][n-i+1]=1;
					k-=2;
					if(k==0)
						break;
				}
			}
		}
		if(tmp%2!=0)
			p[2][n/2+1]=1;
		else if(k==2)
			p[2][n/2+1]=p[3][n/2+1]=1;
		printf("YES\n");
		for( i = 1 ; i <= 4 ; i++)
		{
			for( j = 1 ; j <= n ; j++)
			{
				if(p[i][j])
				{
					printf("#");
				}
				else
				{
					printf(".");
				}
			}
			printf("\n");
		}
	
	}
	return 0;
}

