#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct Node
{
	int d,h;
	bool friend operator<(Node A,Node B)
	{
		return (1.0*A.d/A.h)<(1.0*B.d/B.h);
	}
};
priority_queue<Node> q;
int main()
{
	//freopen("in.txt","r",stdin);
	Node tmp;
	int n,i,x,y,ans;
	while(~scanf("%d",&n))
	{
		while(!q.empty())q.pop();
		int maxi = 0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d%d",&x,&y);
			tmp.d = x;
			tmp.h = y;
			q.push(tmp);
			maxi+=x;
		}
		ans = 0;
		while(!q.empty())
		{
			tmp = q.top();
			ans+=maxi*tmp.h;
			maxi-=tmp.d;
			q.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}