#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int maxn = 100010;
const int inf=0x3f3f3f3f;
vector<string> a,b;
int v[maxn];
int cost[maxn];
int A[maxn];
typedef _int64 ll;
map<string,int> mymap;
int min(int a,int b){return a>b?b:a;}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,m,t,i,x;
	string s;
	while(~scanf("%d%d%d",&n,&k,&m))
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
		{
			cin>>s;
			a.push_back(s);
			mymap[a[i]]=i;
			cost[i]=inf;
		}
		for( i = 0 ; i < n ; i++)
			scanf("%d",&v[i]);
		for( i = 0 ; i < k ; i++)
		{
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d",&x);
				A[x-1]=i;
				cost[i]=min(cost[i],v[x-1]);
			}
		}
		for( i = 0 ; i < m ; i++)
		{
			cin>>s;
			b.push_back(s);
		}
		ll ans = 0;
		for( i = 0 ; i < m ; i++)
		{
			int id = mymap[b[i]];
			ans+=cost[A[id]];			
		}
	//	cout<<ans<<endl;
		printf("%I64d\n",ans);
	}
	return 0;
}

