#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>
using namespace std;
typedef _int64 ll;
const int maxn = 510;
const int inf = 0x3f3f3f3f;
int a[510];
int n,sum,cnt,ans;
struct Node
{
	int deg,index;
	Node(){};
	Node(int deg,int index):deg(deg),index(index){};
}node[maxn];
queue<int>que;
struct Edge
{
	int u,v;
	Edge(){}
	Edge(int u,int v):u(u),v(v){}
}edge[maxn<<1];
int main()
{
	//freopen("in.txt","r",stdin);
	int buf,i;
	while(cin>>n)
	{
		sum=0,cnt=0,ans=0;
		int len = 0;
		for( i = 1 ; i <= n ; i++)
		{
			cin>>buf;
			sum+=buf;
			if(buf==1)que.push(i);
			else node[++len]=Node(buf,i);
		}
		if(sum<(n-1)*2)return 0*puts("NO");
		for( i = 1 ; i < len ; i++)
		{
			edge[++cnt]=Edge(node[i].index,node[i+1].index);
			node[i].deg--;
			node[i+1].deg--;
			ans++;
		}
		if(!que.empty())
		{
			int cur = que.front();
			que.pop();
			edge[++cnt]=Edge(cur,node[1].index);
			node[1].deg--;
			ans++;
		}
		if(!que.empty())
		{
			int cur = que.front();
			que.pop();
			edge[++cnt]=Edge(cur,node[len].index);
			node[len].deg--;
			ans++;
		}
		while(!que.empty())
		{
			int cur=que.front();
			que.pop();
			for( i = 1 ; i <= len ; i++)
			{
				if(node[i].deg>0)
				{
					edge[++cnt]=Edge(node[i].index,cur);
					node[i].deg--;
					break;
				}
			}
		}
		cout<<"YES "<<ans<<endl<<cnt<<endl;
		for( i = 1 ; i <= cnt ; i++)
			cout<<edge[i].u<<" "<<edge[i].v<<endl;
	}
	return 0;
}