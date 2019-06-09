#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 300010;
const int inf = 0x3ffffff;
typedef _int64 ll;
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}
struct Node
{
	int t,b;
}node[maxn];
set<pair<int,int> >myset;
bool cmp1(Node A,Node B)
{
	return A.t>B.t;
}
bool cmp2(Node A,Node B)
{
	return A.b>B.b;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,k,i;
	while(cin>>n>>k)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>node[i].t>>node[i].b;
		sort(node+1,node+n+1,cmp2);
		myset.clear();
		ll sum=0,ans=0;
		if(k==1)
		{
			for( i = 1 ; i <= n ; i++)
			{
				ans=max(ans,ll(node[i].t)*ll(node[i].b));
			}
			printf("%I64d\n",ans);
			continue;
		}
		for( i = 1 ; i <= n ; i++)
		{
			ans=max(ans,(sum+ll(node[i].t))*ll(node[i].b));
			if(myset.size()<k-1)
				sum+=node[i].t,myset.insert(make_pair(node[i].t,i));
			else
			{
				if(node[i].t>((*myset.begin()).first))
				{
					sum-=((*myset.begin()).first);
					sum+=node[i].t;
					myset.erase(myset.begin());
					myset.insert(make_pair(node[i].t,i));
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}