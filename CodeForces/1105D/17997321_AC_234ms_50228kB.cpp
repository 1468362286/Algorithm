#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 1010;
const ll mod = 1000000007;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
char Map[maxn][maxn];
int vist[maxn][maxn];
int v[maxn];
struct Node
{
	int x,y;
	int t;
	Node(){};
	Node(int x,int y,int t):x(x),y(y),t(t){}
};
int dir[4][2]={1,0,-1,0,0,1,0,-1};
queue<Node>A[10],B[10];
int n,m;
bool judge(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&Map[x][y]=='.'&&!vist[x][y])
		return true;
	else
		return false;
}
int bfs(int pos,int v)
{
	while(!B[pos].empty())
	{
		Node tmp = B[pos].front();
		B[pos].pop();
		tmp.t=0;
		A[pos].push(tmp);
	}
	int cnt=0;
	while(!A[pos].empty())
	{
		Node tmp = A[pos].front();
		A[pos].pop();
		if(tmp.t==v)
		{
			B[pos].push(tmp);
			continue;
		}
		for(int i = 0 ; i < 4 ; i++)
		{
			int x = tmp.x+dir[i][0];
			int y = tmp.y+dir[i][1];
			if(judge(x,y))
			{
				A[pos].push(Node(x,y,tmp.t+1));
				vist[x][y]=pos;
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int p,i,j;
	int Ans[10];
	while(cin>>n>>m>>p)
	{
		for( i = 1 ; i <= p ; i++)
			cin>>v[i];
		getchar();
		memset(vist,0,sizeof(vist));
		for( i = 0 ; i < n ; i++)
		{
			for( j = 0 ; j < m ; j++)
			{
				scanf("%c",&Map[i][j]);
				if(Map[i][j]>='1'&&Map[i][j]<='9')
				{
					B[Map[i][j]-'0'].push(Node(i,j,0));
					vist[i][j]=Map[i][j]-'0';
				}
			}
			getchar();
		}
		while(1)
		{
			int ans=0;
			for( i = 1 ; i <= p ; i++)
			{
				ans+=bfs(i,v[i]);
			}
			if(ans==0)break;
		}
		memset(Ans,0,sizeof(Ans));
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < m ; j++)
				if(vist[i][j])
				{
					Ans[vist[i][j]]++;
				}
		for( i = 1 ; i <= p ; i++)
			printf("%d ",Ans[i]);
		printf("\n");
	}
    return 0;
}