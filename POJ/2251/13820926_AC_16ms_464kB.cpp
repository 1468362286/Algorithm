#include <iostream>
#include <string>
#include <string.h>
#include <queue>
using namespace std;
char map[35][35][35];
int vist[35][35][35];
int dir[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
int L,R,C;
struct Point
{
	int x,y,z;
	int step;
}source,end,tmp,temp;

int BFS()
{
	queue<Point> p;
	memset(vist,0,sizeof(vist));
	/*
	while(!p.empty())
		p.pop;
		*/
	p.push(source);
	while(!p.empty())
	{
		tmp=p.front();
		p.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.z;
		vist[z][x][y]=1;
		if(x==end.x&&y==end.y&&z==end.z)
		{
			return tmp.step;
		}
		for(int i = 0 ; i < 6 ; i++)
		{
			int dx = x+dir[i][0];
			int dy = y+dir[i][1];
			int dz = z+dir[i][2];
			temp.x=dx,temp.y=dy,temp.z=dz;
			if(dz>=0&&dz<L&&dx>=0&&dx<R&&dy>=0&&dy<C&&map[dz][dx][dy]!='#')
			{
				if(!vist[dz][dx][dy])
				{
					temp.step=tmp.step+1;
					p.push(temp);
					vist[dz][dx][dy]=1;
				}
			}
		}
	}
	return -1;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k;
	while(cin>>L>>R>>C)
	{
		if(L==0&&R==0&&C==0)
			break;
		for( i = 0 ; i < L ; i++)
		{
			for( j = 0 ; j < R ; j++)
			{
				scanf("%s",&map[i][j]);
				for( k = 0 ; k < C ; k++)
					if(map[i][j][k]=='S')
						source.z=i,source.x=j,source.y=k,source.step=0;
					else if(map[i][j][k]=='E')
						end.z=i,end.x=j,end.y=k;
			}
		}
		int ans=BFS();
		if(ans==-1)
			printf("Trapped!\n");
		else
		printf("Escaped in %d minute(s).\n",ans);
	}
	return 0;
}