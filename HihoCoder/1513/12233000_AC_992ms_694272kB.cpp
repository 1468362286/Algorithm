#include <stdio.h>
#include <iostream>
#include <bitset>
using namespace std;
bitset<30010> A[30010][6],ans;
int a[30010][6];
int Rank[30010][6];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,x;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ; i++)
		{
			for( j = 1 ; j <= 5 ; j++)
			{
				scanf("%d",&a[i][j]);
				Rank[a[i][j]][j]=i;
			}
		}
		for( j = 1 ; j <= 5 ; j++)
			for( i = 2 ; i <= n ; i++)
			{
				A[i][j] = A[i-1][j];
				A[i][j].set(Rank[i-1][j]);
			}
		for( i = 1 ; i <= n ; i++)
		{
			ans = A[a[i][1]][1];
			for( j = 2 ; j <= 5; j++)
			ans=(ans&A[a[i][j]][j]);
			printf("%d\n",ans.count());
		}
		
	}
	return 0;
}

/*耗时：989ms*/