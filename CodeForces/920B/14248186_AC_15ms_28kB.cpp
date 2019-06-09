#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int max(int a,int b){return a>b?a:b;}
struct Node
{
	int l,r;
	int id;
}node[maxn];
int ans[maxn];
bool cmp(Node A,Node B)
{
	return A.l<B.l;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int T,n,i;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for( i = 1 ; i <= n ; i++)
			cin>>node[i].l>>node[i].r,node[i].id=i;
		sort(node+1,node+n+1,cmp);
		int now=node[1].l;
		ans[node[1].id]=now;
		now++;
		for( i = 2 ; i <= n ; i++)
		{
			if(node[i].r>=now)
			{
				int id=node[i].id;
				now=max(now,node[i].l);
				ans[id]=now;
				now++;
			}
			else
				ans[node[i].id]=0;
		}
		for( i = 1 ; i <= n ; i++)
			printf("%d%s",ans[i],i==n?"\n":" ");
	}
	return 0;
}