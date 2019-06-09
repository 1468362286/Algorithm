#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int maxn = 200010;
map<int,int> mymap[maxn];
vector<int> vec[maxn];
int a[maxn],vist[maxn];
int n;

void dfs(int s,int fa)
{
	for(int i = 0 ; i < vec[s].size() ; i++)
	{
		int to=vec[s][i];
		if(to!=fa)
		{
			mymap[s][to]=1;
			dfs(to,s);
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int x,y,i;
	while(cin>>n)
	{
		for( i = 1 ; i < n ; i++)
		{
			cin>>x>>y;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		dfs(1,0);
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		if(a[1]!=1)
		{
			cout<<"No"<<endl;
			continue;
		}
		queue<int> que;
		while(!que.empty())que.pop();
		memset(vist,0,sizeof(vist));
		que.push(1);
		vist[1]=1;
		int p =2;
		while(!que.empty())
		{
			int s = que.front();
			que.pop();
			vist[s]=1;
			while(p<=n&&mymap[s].find(a[p])!=mymap[s].end())
			{
				que.push(a[p]);
				p++;
			}
		}
		int flag=0;
		for( i = 1 ; i <= n ; i++)
			if(!vist[i])
			{
				flag=1;
				break;
			}
		if(flag)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}