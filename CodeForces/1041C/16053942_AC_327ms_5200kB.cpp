#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 200010;
int vist[maxn];
struct Node
{
	int x,id;
	bool operator<(const Node& A)
	{
		return x<A.x;
	}
}node[maxn];
int a[maxn],Id[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,d,i,x;
	while(cin>>n>>m>>d)
	{
		for( i = 1 ; i <= n ; i++)
		{
			cin>>x;
			node[i].x=x,node[i].id=i;
		}
		sort(node,node+n+1);
		memset(vist,0,sizeof(vist));
		int cnt=0;
		queue<int> que;
		while(!que.empty())que.pop();
		que.push(1),vist[node[1].id]=++cnt;
		for( i = 2 ; i <= n ; i++)
		{
			if(node[i].x-d-1>=node[que.front()].x)
			{
				vist[node[i].id]=vist[node[que.front()].id];
				que.pop();
			}
			else
			{
				vist[node[i].id]=++cnt;
			}
			que.push(i);
		}
		cout<<cnt<<endl;
		for( i = 1 ; i <= n ; i++)
		{
			cout<<vist[i]<<" ";
		}
		cout<<endl;

	}
	return 0;
}