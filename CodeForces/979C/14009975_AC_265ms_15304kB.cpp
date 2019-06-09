#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<cmath>  
#include<string>  
#include<algorithm>  
#include<vector>  
#include<queue>  
#include<set>  
#include<map>  
#include<stack>  
using namespace std;
typedef _int64 ll;
const int inf = 0x3f3f3f3f;
const int maxn=300000+500;  
int n,m,x,y;  
vector<int>e[maxn];  
bool vis[maxn],xoy[maxn];  
int pre[maxn];

void init()
{
	memset(xoy,false,sizeof(xoy));
	memset(vis,false,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	scanf("%d%d%d",&n,&x,&y);
	m=n-1;
	for(int i = 0 ; i < m ; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
}
 
void predfs(int u,int fa)
{
	pre[u]=fa;
	if(u==y)
		return;
	int size = e[u].size();
	for(int i = 0 ; i < size ; i++)
	{
		int v= e[u][i];
		if(v!=fa)
		{
			predfs(v,u);
		}
	}
}

int dfs(int u)
{
	vis[u]=true;
	int size = e[u].size();
	int here=1;
	for(int i = 0 ; i < size ; i++)
	{
		int v = e[u][i];
		if(!vis[v]&&!xoy[v]&&v!=x&&v!=y)
		{
			here+=dfs(v);
		}
	}
	return here;
}

int main()
{
	//freopen("in.txt","r",stdin);
	init();
	predfs(x,-1);
	for(int i = pre[y] ; i != x ; i = pre[i])
	{
		xoy[i]=true;
	}
	int cntx=dfs(x);
	int cnty=dfs(y);
	ll ans = (ll)1*n*(n-1)-(ll)cntx*cnty;
	printf("%I64d\n",ans);
	return 0;
}