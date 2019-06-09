#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
using namespace std;
const int maxn = 2010*100;
const int inf = 999999;
typedef _int64 ll;

//int map[maxn][maxn];
vector<pair<int,ll> >map[maxn];
int n,m;
ll dist[maxn],a[maxn];
int vist[maxn];

int min(int a,int b){return a>b?b:a;}


void Dijkstra()
{
	int i;
	set<pair<ll,int> >q;
	for( i = 1 ; i <= n ; i++)
	{
		dist[i]=a[i];
		q.insert(make_pair(dist[i],i));
	}
	while(!q.empty())
	{
		int v=q.begin()->second;
		q.erase(q.begin());

		for( i = 0 ; i < map[v].size() ; i++)
		{
			int u = map[v][i].first;
			ll w = map[v][i].second;

			if(dist[u]>dist[v]+w)
			{
				q.erase(make_pair(dist[u],u));
				dist[u]=dist[v]+w;
				q.insert(make_pair(dist[u],u));
			}
		}
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,u,v;
	ll x;
	while(cin>>n>>m)
	{
		for( i = 0 ; i < m ; i++)
		{
			scanf("%d%d%I64d",&u,&v,&x);
			map[u].push_back(make_pair(v,2*x));
			map[v].push_back(make_pair(u,2*x));
		}
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%I64d",&a[i]);
		}
		Dijkstra();
		for( i = 1 ; i <= n ; i++)
		{	
			printf("%I64d ",dist[i]);
		}
	}
	return 0;
}