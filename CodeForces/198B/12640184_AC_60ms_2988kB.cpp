#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
const int maxn=100010;
char map[2][maxn];
int vist[2][maxn];
int n,k;
struct Node
{
	int x,y;
	int step;
	Node(){};
	Node(int x,int y):x(x),y(y){}
}S,s,to;

bool check(Node Pos)
{	
	if(Pos.y<0||map[Pos.x][Pos.y]=='X'||Pos.step>Pos.y)
		return false;
	return true;
}	
bool bfs()
{
	memset(vist,0,sizeof(vist));
	S=Node(0,0);
	S.step=0;
	queue<Node> p;
	while(!p.empty())p.pop();
	p.push(S);
	vist[0][0]=1;
	while(!p.empty())
	{
		s=p.front();
		p.pop();
		for(int i = 0 ; i < 3 ; i++)
		{
			if(i==0)
			{
				to.x=s.x;
				to.y=s.y+1;
			}
			else if(i==1)
			{
				to.x=s.x;
				to.y=s.y-1;
			}
			else if(i==2)
			{
				to.x=!s.x;
				to.y=s.y+k;
			}
			to.step=s.step+1;
			if(to.y>n)
				return true;
			if(check(to)&&!vist[to.x][to.y])
			{
				p.push(to);
				vist[to.x][to.y]=1;
			}
		}
	}
	return false;
}
int main()
{
	//freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&n,&k))
	{
		scanf("%s%s",&map[0],&map[1]);
		if(bfs())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}