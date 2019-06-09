#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node
{
	int x,y,s;
	node(){};
	node(int _x,int _y,int _s)
	{
		x=_x;
		y=_y;
		s=_s;
	}
};
const int maxn = 1010;
vector<node>v;
char g[maxn][maxn];
bool vist[maxn][maxn];
int n,m;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
void solve(int x,int y)
{
	int ans=1,f=1,flag=0;
	while(f)
	{
		for(int i = 0 ; i < 4 ; i++)
		{
			int xx = x+dx[i]*ans,yy=y+dy[i]*ans;
			if(xx<0||yy<0||xx>=n||y>=m||g[xx][yy]!='*')
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			vist[x+dx[0]*ans][y+dy[0]*ans]=vist[x+dx[1]*ans][y+dy[1]*ans]=vist[x+dx[2]*ans][y+dy[2]*ans]=vist[x+dx[3]*ans][y+dy[3]*ans]=vist[x][y]=true;
			flag=1;
			ans++;
		}
		else
			break;
	}
	if(flag)v.push_back(node(x+1,y+1,ans-1));
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d",&n,&m))
	{
		for( i = 0 ; i < n ; i++)
			scanf("%s",g[i]);
		memset(vist,false,sizeof(vist));
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < m ; j++)
				if(g[i][j]=='*')
					solve(i,j);
		bool flag=true;
		for( i = 0 ; i < n ; i++)
		{
			for( j = 0 ; j < m ; j++)
			{
				if(g[i][j]=='*'&&!vist[i][j])
				{
					flag=false;
					break;
				}
			}
			if(!flag)break;
		}
		if(!flag||v.size()>=n*m)
			printf("-1\n");
		else
		{
			printf("%d\n",v.size());
			for( i = 0 ; i < v.size() ; i++)
				printf("%d %d %d\n",v[i].x,v[i].y,v[i].s);
		}
	}
	return 0;
}