#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
const int maxn = 300010;
int n,m;
char map[maxn];
int deg[maxn];
int dp[maxn][30];
vector<int> vec[maxn];
queue<int> p;
int max(int a,int b){return a>b?a:b;}
int main()
{
//	freopen("in.txt","r",stdin);
	int u,v,i,j;
	while(~scanf("%d%d",&n,&m))
	{
//		memset(dp,0,sizeof(dp));
		getchar();
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%c",&map[i]);
			vec[i].clear();
			dp[i][map[i]-'a'+1]=1;
		}
		getchar();
		while(!p.empty())p.pop();
		memset(deg,0,sizeof(deg));
		for( i = 1 ; i <= m ; i++)
		{
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			deg[v]++;
		}
		for( i = 1 ; i <= n ; i++)
		{
			if(deg[i]==0)
				p.push(i);
		}
		int cnt=0;
		while(!p.empty())
		{
			int to = p.front();
			p.pop();
			for( i = 0 ; i < vec[to].size() ; i++)
			{
				int k = vec[to][i];
				int tmp = map[k]-'a'+1;
				for( j = 1 ; j <= 26 ; j++)
				{
					if(tmp==j)
						dp[k][j]=max(dp[k][j],dp[to][j]+1);
					else
						dp[k][j]=max(dp[k][j],dp[to][j]);
				}
				deg[k]--;
				if(deg[k]==0)
					p.push(k);
			}
			cnt++;
		}
	//	cout<<dp[5][26]<<endl;
		int ansi,ansj;
		if(cnt==n)
		{
			int ans=0;
			for( i = 1 ; i <= n ; i++)
				for( j = 1 ; j <= 26 ; j++)
				{
				//	ans=max(ans,dp[i][j]);
					if(ans<dp[i][j])
					{
						ans=dp[i][j];
						ansi=i;
						ansj=j;
					}
				}
			cout<<ans<<endl;
	//		cout<<ansi<<" "<<ansj<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}