#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
using namespace std;
typedef _int64 ll;
const int maxn = 100010;
ll a[maxn],sum[maxn];
int b[maxn];
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;
multiset<ll>ms; 
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x;
	while(~scanf("%d",&n))
	{
		sum[0] = 0;
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%I64d",&a[i]);
			sum[i] = sum[i-1]+a[i];
		}
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&b[i]);
		}
		s.clear(),ms.clear();
		s.insert(make_pair(n,1));
		ms.insert(sum[n]);
		for( i = 1 ; i <= n ; i++)
		{
			it = s.lower_bound(make_pair(b[i],1));
			int r = it->first,l = it->second;
			s.erase(*it);
			s.insert(make_pair(b[i]-1,l));
			s.insert(make_pair(r,b[i]+1));
			ms.erase(ms.find(sum[r]-sum[l-1]));
			ms.insert(sum[b[i]-1]-sum[l-1]);
			ms.insert(sum[r]-sum[b[i]]);

			multiset<ll>::reverse_iterator reit = ms.rbegin();
			printf("%I64d\n",*reit);
		}
	}
	return 0;
}

