#include <iostream>
#include <string>
using namespace std;
const int maxn = 2*100010;
int ans;
int head[maxn];
int siz[maxn];
int cnt=1;
struct Edge
{
	int to,nxt;
}edge[maxn];

void add(int x,int y)
{
	edge[cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt++;
}

void dfs(int x,int fa)
{
	siz[x]=1;
	for(int i = head[x] ; i ; i = edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			dfs(to,x);
			siz[x]+=siz[to];
		}
	}
	if(!(siz[x]&1))siz[x]=0,ans++;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x,y;
	while(cin>>n)
	{
		for( i = 1 ; i < n ; i++)
		{
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		if(n%2==0)
		{
			ans=0;
			dfs(1,-1);
			ans--;
			cout<<ans<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}