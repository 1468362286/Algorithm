#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
typedef _int64 ll;
const int maxn = 200010;
ll a[maxn];
ll pre_sum[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,q,i;
	ll x;
	while(cin>>n>>q)
	{
		memset(pre_sum,0,sizeof(pre_sum));
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%I64d",&a[i]);
			pre_sum[i]=pre_sum[i-1]+a[i];
		}
		ll dmg=0;
		while(q--)
		{
			scanf("%I64d",&x);
			dmg+=x;
			if(dmg>=pre_sum[n])
			{
				dmg=0;
				printf("%d\n",n);
			}
			else
			{
				int len = upper_bound(pre_sum+1,pre_sum+n+1,dmg)-pre_sum;
				cout<<n-len+1<<endl;
			}
		}
	}
	return 0;
}