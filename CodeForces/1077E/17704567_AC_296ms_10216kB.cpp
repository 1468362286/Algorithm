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
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 200010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
int dp[maxn*2];
map<int,int>mymap;
struct Node
{
	int x,cn;
}node[maxn];
bool cmp(Node A,Node B)
{
	return A.cn<B.cn;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i,j;
	while(cin>>n)
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
			cin>>a[i],mymap[a[i]]++;
		map<int,int>::iterator it;
		int cnt=0;
		for( it = mymap.begin() ; it!=mymap.end() ; it++)
		{
			node[cnt].x=(*it).first;
			node[cnt++].cn=(*it).second;
		}
		sort(node,node+cnt,cmp);
		int ans=0;
		for( i = cnt-1 ; i >= 0 ; i--)
			for( j = 1 ;  j <= node[i].cn ; j++)
			{
				dp[j]=max(dp[j],j+dp[j*2]);
				ans=max(ans,dp[j]);
			}
		cout<<ans<<endl;
	}
	return 0;
}