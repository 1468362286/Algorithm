#include <stdio.h>
#include <vector>
using namespace std;

typedef _int64 ll;
const int maxn = 100005;
bool vis[maxn];
vector<int> v[maxn];
int color[maxn];

void dfs(int s)
{
	vis[s] = 1;
	if(color[s]==0)
		color[s]=1;
	
	for(int i = 0 ; i < v[s].size() ; i++)
	{
		int to = v[s][i];
		if(!vis[to])
		{
			if(color[s]==1)
				color[to] = 2;
			else
				color[to] = 1;
			vis[to] = 1;
			dfs(to);
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		for( i =1 ; i <= n ; i++)
			v[i].clear();
		for( i = 0 ; i < n-1 ; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1);

		ll cnt1=0,cnt2=0;
		for( i = 1 ; i <= n ; i++)
		{
			if(color[i]==1)
				cnt1++;
			else
				cnt2++;
		}
		printf("%I64d\n",cnt1*cnt2-(n-1));
	}
	return 0;
}