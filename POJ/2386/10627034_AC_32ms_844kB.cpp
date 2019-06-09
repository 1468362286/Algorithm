#include <stdio.h>
const int maxn=101;
char map[maxn][maxn];
int n,m;
int dir[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
void DFS_floodfill(int x,int y)
{
	int i,j;
	map[x][y]='.';
	for( i = 0 ; i < 8 ; i++)
	{
		int xx = x+dir[i][0];
		int yy = y+dir[i][1];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&map[xx][yy]=='W')
		DFS_floodfill(xx,yy);
	}
	/*
	for( i = -1 ; i <=1 ; i++)
		for( j = -1 ; j <= 1 ; j++)
		{
			int xx = x+i;
			int yy = y+j;
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&map[xx][yy]=='W')
			DFS_floodfill(xx,yy);
		}
		*/
}
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d",&n,&m))
	{
		int ans = 0;
		getchar();
		for( i = 1 ; i <= n ; i++)
		{
			for( j = 1 ; j <= m ; j++)
			{
				scanf("%c",&map[i][j]);
			}
			getchar();
		}
		for( i = 1 ; i <= n ; i++)
			for( j = 1 ; j <= m ; j++)
				if(map[i][j]=='W')
				{
					DFS_floodfill(i,j);
					ans++;
				}
		printf("%d\n",ans);
	}
	return 0;
}