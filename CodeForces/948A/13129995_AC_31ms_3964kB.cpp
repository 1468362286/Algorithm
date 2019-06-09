#include <stdio.h>
#include <string.h>
char map[510][510];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	while(~scanf("%d%d",&n,&m))
	{
		int flag=true;
		for( i = 0 ; i < n ; i++)
			scanf("%s",&map[i]);
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < m ; j++)
			{
				if(map[i][j]=='S')
				{
					for( k = 0 ; k < 4 ; k++)
					{
						int dx=i+dir[k][0];
						int dy=j+dir[k][1];
						if(dx>=0&&dx<n&&dy>=0&&dy<m)
						{
							if(map[dx][dy]=='.')
								map[dx][dy]='D';
							else if(map[dx][dy]=='W')
							{
								flag=false;
							}
						}
					}
				}
			}
		if(flag)
		{
			printf("Yes\n");
			for( i = 0 ; i < n ; i++)
				printf("%s\n",map[i]);
		}
		else
			printf("No\n");
	}
	return 0;
}