#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1100;
int d[maxn];
int vist[maxn];
struct Node
{
	int a;
	int pi;
	/*
	bool friend operator<(Node A,Node B)
	{
		return A.pi<B.pi;
	}
	*/
};
queue<Node> p;

int main()
{
//	freopen("in.txt","r",stdin);
	Node tmp;
	int T,i,j,k,n,x,m,maxi,maxii;
	scanf("%d",&T);
	while(T--)
	{
		while(!p.empty())p.pop();
		scanf("%d%d",&n,&m);
		for( i = 0 ; i < n ; i++)
		{
			vist[i]=0;
			scanf("%d",&d[i]);
			tmp.a = i;
			tmp.pi = d[i];
			p.push(tmp);
		}
		int ans = 0;
		while(!p.empty())
		{
			tmp = p.front();
			int flag = 0;
			for( i = 0 ; i < n ; i++)
			{
				if(d[i]>tmp.pi&&!vist[i]&&i!=tmp.a)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
			{
				p.pop();
				p.push(tmp);
			}
			else
			{
				vist[tmp.a] = 1;
				p.pop();
				ans++;
				if(tmp.a==m)
					break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}