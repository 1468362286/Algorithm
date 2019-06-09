#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100010;
int n,m,k,s;
int vist[2*maxn];
int dist[110][maxn];
vector<int> Goods[maxn];
vector<int> vec[2*maxn];

struct Node
{
	int to,step;
	Node(int to,int step):to(to),step(step){}
	Node(){}
};

void bfs(int s,int id)
{
	memset(vist,0,sizeof(vist));
	queue<Node> p;
	while(!p.empty()) p.pop();
	p.push(Node(s,-1));
	vist[s]=1;
	while(!p.empty())
	{
		Node tmp = p.front();
		int to = tmp.to;
		int step = tmp.step;
		dist[id][to]=step;
		p.pop();
		for(int i = 0 ; i < vec[to].size() ; i++)
		{
			int v = vec[to][i];
			if(!vist[v])
			{
				p.push(Node(v,step+1));
				vist[v]=1;
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int u,v,x,i,j;
	while(cin>>n>>m>>k>>s)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>x,Goods[x].push_back(i);
		for( i = 0 ; i < m ; i++)
		{
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		int cnt;
		memset(dist,0,sizeof(dist));
		for( i = 1 ; i <= k ; i++)
		{
			cnt=maxn+1+i;
			for( j = 0 ; j < Goods[i].size() ; j++)
			{
				vec[cnt].push_back(Goods[i][j]);					
			}
			bfs(cnt,i);
			/*
			for( j = 1 ; j <= n ; j++)
			{
				cout<<dist[i][j]<<" ";
			}
			cout<<endl;
			*/
		}
		vector<int> tmp;
		for( i = 1 ; i <= n ; i++)
		{
			int ans=0;
			tmp.clear();
			for( j = 1 ; j <= k ; j++)
			{
				tmp.push_back(dist[j][i]);
			}
			sort(tmp.begin(),tmp.end());
			for( j = 0 ; j < s ; j++)
				ans+=tmp[j];
			cout<<ans<<" ";
		}
		cout<<endl;
	}
	return 0;
}