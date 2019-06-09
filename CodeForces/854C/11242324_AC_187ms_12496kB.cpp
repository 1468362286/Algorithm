#include <stdio.h>
#include <queue>
using namespace std;
const int maxn = 1000010;
typedef _int64 ll;
int ans[maxn];
struct Node
{
	ll id;
	ll c;
	/*
	bool operator<(const Node &tmp)const
	{
		return c<tmp.c;
	}
	Node(int i=0,int c = 0):id(i),c(c){}
	*/
	Node()
	{
		id = 0;
		c = 0;
	}
	friend bool operator < (const Node &a, const Node &b) 
	{
		return a.c < b.c; 
	}
}A;
/*
bool operator < (const Node &a, const Node &b) 
{
	return (a.c < b.c); 
}
*/
priority_queue<Node> q;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,k,i;
	ll x;
	while(~scanf("%d%d",&n,&k))
	{
		ll cost=0;
		for( i = 1 ; i <= n+k ; i++)
		{
			if(i<=n)
			{
				scanf("%I64d",&x);
				A.id = i;
				A.c = x;
				q.push(A);
			}
			if(i>=k+1)
			{
				Node tmp = q.top();
				cost+=tmp.c*(i-tmp.id);
				q.pop();
				ans[tmp.id] = i;
			}
		}
		printf("%I64d\n",cost);
		for( i = 1 ; i <= n ; i++)
			i==1?printf("%d",ans[i]):printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
