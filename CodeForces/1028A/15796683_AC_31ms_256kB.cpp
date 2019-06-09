#include <iostream>
#include <string>
#include <math.h>
using namespace std;
char map[120][120];
int main()
{
	int n,m,i,j;
	while(cin>>n>>m)
	{
		getchar();
		int flag=0;
		int cnt=0;
		int ansi=0,ansj=0;
		for( i = 1 ; i <= n ; i++)
		{
			for( j = 1 ; j <= m ; j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='B')
				{
					if(!flag)
						ansi=i,ansj=j,flag=1;
					cnt++;
				}
			}
			getchar();
		}
		int len = int(sqrt(cnt));
		printf("%d %d\n",ansi+len/2,ansj+len/2);
	}
	return 0;
}