#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
typedef _int64 ll;
const int maxn = 300010;
ll a[maxn];
int ans[600010];
struct Node
{
	ll x;
	int id;
	bool friend operator<(Node A,Node B)
	{
		return A.x<B.x;
	}
};
priority_queue<Node> p;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	ll cost;
	Node tmp;
	while(~scanf("%d%d",&n,&k))
	{
		cost=0;
		while(!p.empty())p.pop();
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%I64d",&a[i]);
		}
		for( i = 1 ; i <= n+k ; i++)
		{
			if(i<=n)
			{
				tmp.x = a[i];
				tmp.id = i;
				p.push(tmp);
			}
			if(i>=k+1)
			{
				tmp = p.top();
				cost+=tmp.x*(i-tmp.id);
				p.pop();
				ans[tmp.id] = i;
			}
		}
		printf("%I64d\n",cost);
		for( i = 1 ; i <= n ; i++)
		{
			i==1?printf("%d",ans[i]):printf(" %d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}