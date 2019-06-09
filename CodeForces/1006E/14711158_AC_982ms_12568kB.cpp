#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 200010;
vector<int> vec[maxn];
int ans[maxn];
int in[maxn],out[maxn];
int tot;
void dfs(int x)
{
	in[x]=++tot;
	ans[tot]=x;
	for(int i = 0 ; i < vec[x].size() ; i++)
	{
		dfs(vec[x][i]);
	}
	out[x]=tot;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,q,i,x,u,k;
	while(cin>>n>>q)
	{
		for( i = 1 ; i <= n ; i++)
			vec[i].clear();
		for( i = 2 ; i <= n ; i++)
		{
			cin>>x;
			vec[x].push_back(i);						
		}
		memset(ans,0,sizeof(ans));
		tot=0;
		dfs(1);
		while(q--)
		{
			cin>>u>>k;
			if(out[u]-in[u]+1<k)
				cout<<"-1"<<endl;
			else
				cout<<ans[in[u]+k-1]<<endl;

		}
	}
	return 0;
}
