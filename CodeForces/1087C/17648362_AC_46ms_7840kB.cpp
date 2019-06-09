#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn = 1000010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
struct Node
{
	int x,y;
}node[3];
pair<int,int>ans[maxn];
bool cmp1(Node A,Node B)
{
	return A.x<B.x;
}
bool cmp2(Node A,Node B)
{
	return A.y<B.y;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int i,j;
	int cnt=0;
	for( i = 0 ; i < 3 ; i++)
	{
		cin>>node[i].x>>node[i].y;
	}
	sort(node,node+3,cmp1);
	int mid = node[1].x;
	sort(node,node+3,cmp2);
	for( i = node[0].y ; i <= node[2].y ; i++)
		ans[++cnt]=make_pair(mid,i);
	for( i = 0 ; i < 3 ; i++)
		if(node[i].x!=mid)
		{
			int upper=max(mid,node[i].x);
			for( j = min(mid,node[i].x) ; j <= upper ; j++)
				ans[++cnt]=make_pair(j,node[i].y);
		}
	sort(ans+1,ans+cnt+1);
	cnt = int(unique(ans+1,ans+1+cnt)-ans-1);
	cout<<cnt<<endl;
	for( i = 1 ; i <= cnt ; i++)
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	return 0;
}