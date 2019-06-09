#include <stdio.h>
#include <queue>
using namespace std;
const int maxn=101;
char map[maxn][maxn];
int n,m;
int dir[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};

struct Node
{
	int x,y;
}s;

void BFS_floodfill(struct Node a)
{
	Node tmp;
	queue<Node> q;
	while(!q.empty())
		q.pop();
	int i;
	q.push(a);
	map[a.x][a.y]='.';
	while(!q.empty())
	{
		Node ss = q.front();
		q.pop();
		for( i = 0 ; i < 8 ; i++)
		{
			tmp.x = ss.x+dir[i][0];
			tmp.y = ss.y+dir[i][1];
			if(tmp.x>=1&&tmp.x<=n&&tmp.y>=1&&tmp.y<=m&&map[tmp.x][tmp.y]=='W')
			{
				q.push(tmp);
				map[tmp.x][tmp.y]='.';			
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
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
					s.x = i;
					s.y = j;
					BFS_floodfill(s);
					ans++;
				}
		printf("%d\n",ans);
	}
	return 0;
}

/*
耗时：
题目大意
给定一个n*m的地图，‘W’表示积水，‘.’表示空地，积水是八连通的，求有多少个积水块。
分析
本题是典型的求联通块个数的基础题，思路即用floodfill（漫水填充法），扫描一遍图，每遇到一个‘W’计数器加一，并深搜或者广搜把相邻的‘W’填充为‘.’，直到图上没有积水。 
本题要注意字符串的输入：要不就用cin,要不就用getchar()处理好换行符。

*/