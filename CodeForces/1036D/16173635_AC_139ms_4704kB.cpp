#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
const int maxn = 300010;
ll a[maxn],b[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	scanf("%I64d",&n);
	ll sum1 = 0;
	for( i = 1; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
		sum1+=a[i];
	}
	int m;
	scanf("%d",&m);
	ll sum2=0;
	for( i = 1 ; i <= m ; i++)
	{
		scanf("%I64d",&b[i]);
		sum2+=b[i];
	}
	if(sum1!=sum2)
	{
		puts("-1");
		return 0;
	}
	int pos1=1,pos2=1;
	sum1=0,sum2=0;
	int ans=0;
	while(pos1<=n&&pos2<=m)
	{
		if(sum1==sum2&&sum1>0)
		{
			ans++;
			sum1=0;
			sum2=0;
		}
		if(sum1>sum2)
			sum2+=b[pos2++];
		else
			sum1+=a[pos1++];
	}
	if(sum1||sum2)
		ans++;
	printf("%d\n",ans);
	return 0;
}