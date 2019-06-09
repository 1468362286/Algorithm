#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn=200010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int a[maxn];
int cnt[2][(1<<20)+3];
ll min(ll a,ll b){return a>b?b:a;}
ll H,n;

int solve()
{
	int cnt=0;
	for(int i = 0 ; ; i++)
	{
		H+=a[i%n];
		cnt++;
		if(H<=0)
		{
			break;
		}
	}
	return cnt;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif

	int i;
	while(~scanf("%I64d%I64d",&H,&n))
	{
		ll sum=0;
		ll mina=inf;
		for( i = 0 ; i < n ; i++)
			cin>>a[i],sum+=a[i],mina=min(mina,sum);
		ll cnt=0;
		if(sum>=0&&H+mina>0)
		{
			cout<<-1<<endl;
			continue;
		}
		else if(H+mina<=0)
		{
			cout<<solve()<<endl;
		}
		else
		{
			if(mina<=sum)
		//	cnt = (H)/(-sum)-mina/sum;
			{
				cnt = (H+mina)/(-sum);
			}
			else cnt=H/(-sum);
			H+=cnt*sum;
			ll ans=n*cnt+solve();
			printf("%I64d\n",ans);
		}
	}
	return 0;
}