#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 2*100010;
typedef _int64 ll;
ll a[maxn],b[maxn];
ll pre_sum[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i;
	while(cin>>n>>m)
	{
		for( i = 0 ; i < n ; i++)
		{
			scanf("%I64d",&a[i]);
			if(i==0)
				pre_sum[i]=a[i];
			else
				pre_sum[i]=pre_sum[i-1]+a[i];
		}
		ll room;
		for( i = 1 ; i <= m ; i++)
		{
			scanf("%I64d",&b[i]);
			ll pos = lower_bound(pre_sum,pre_sum+n,b[i])-pre_sum;
			if(pos==0)
				room = b[i];
			else
				room = b[i]-pre_sum[pos-1];
			printf("%I64d %I64d\n",pos+1,room);
		}
		
	}
	return 0;
}