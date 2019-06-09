#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn = 300010;
typedef _int64 ll;
template<class T>
inline T Max(T a,T b){return a>b?a:b;}
typedef struct Node
{
	ll sum,pos;
	bool operator<(const Node &a)const
	{
		if(a.sum==sum)
			return a.pos<pos;
		return a.sum<sum;
	}
}node;

struct query
{
	ll sum,pos;
}edge[maxn];
priority_queue<node> qu;
bool cmp(query a,query b)
{
	return a.pos<b.pos;
}

ll num,n;

int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	scanf("%I64d",&n);
	node no,po;
	while(!qu.empty())
		qu.pop();
	for( i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&num);
		no.pos=i;no.sum=num;
		qu.push(no);
	}
	ll tot=0;
	while(!qu.empty())
	{
		if(qu.size()==1)
		{
			no=qu.top();
			qu.pop();
			edge[tot].sum=no.sum;
			edge[tot++].pos=no.pos;
			break;
		}
		no=qu.top();qu.pop();
		po=qu.top();qu.pop();
		if(no.sum==po.sum)
		{
			no.sum*=2;
			no.pos=Max(no.pos,po.pos);
			qu.push(no);
		}
		else
		{
			edge[tot].sum=no.sum;
			edge[tot++].pos=no.pos;
			qu.push(po);
		}
	}
	sort(edge,edge+tot,cmp);
	printf("%I64d\n",tot);
	for( i = 0 ; i < tot ; i++)
	{
		printf("%I64d",edge[i].sum);
		if(i!=tot-1)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}