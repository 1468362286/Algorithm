#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;
const int maxn=300010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int n;
int a[maxn];
vector<int>g[maxn];
int red,blue;
int ans;

pair<int,int> dfs(int v,int p=-1)
{
	int r=(a[v]==1),b=(a[v]==2);
	pair<int,int>tmp;
	for(int i = 0 ; i < g[v].size() ; i++)
	{
		if(g[v][i]!=p)
		{
			tmp=dfs(g[v][i],v);
			ans+=(tmp.first==red&&tmp.second==0);
			ans+=(tmp.first==0&&tmp.second==blue);
			r+=tmp.first;
			b+=tmp.second;
		}
	}
	return make_pair(r,b);
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	scanf("%d",&n);
	for( i = 0 ; i < n ; i++)
	{
		scanf("%d",&a[i]);
		red+=(a[i]==1);
		blue+=(a[i]==2);
	}
	for( i = 0 ; i < n-1 ; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		--v,--u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	ans=0;
	dfs(0);
	printf("%d\n",ans);
	return 0;
}