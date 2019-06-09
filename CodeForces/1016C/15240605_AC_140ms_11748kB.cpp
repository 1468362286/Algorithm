#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
const int maxn = 300010;
ll a[maxn],b[maxn],n;
ll ans1[maxn],ans2[maxn],sum[maxn];
ll max(ll a,ll b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	scanf("%I64d",&n);
	for( i = 1 ; i <= n ; i++)
		scanf("%I64d",&a[i]);
	for( i = 1 ; i <= n ; i++)
		scanf("%I64d",&b[i]);
	for( i = n ; i >= 1 ; i--)
		sum[i]=sum[i+1]+a[i]+b[i];
	for( i = n ; i >= 1 ; i--)
	{
		ans1[i]=ans1[i+1]+sum[i+1]+b[i]*((n-i)*2+1);
		ans2[i]=ans2[i+1]+sum[i+1]+b[i]+a[i+1]*(n-i)*2;
	}
	ll ans=0,ans3=0;
	for(ll x = 0 ; x < n ; x++)
	{
		ll now = x*2;
		if(x%2==0)
			ans=max(ans,max(ans1[x+1],ans2[x+1])+ans3+sum[x+1]*(x*2));
		if(x%2==0)
		{
			ans3+=a[x+1]*(x*2);
			ans3+=b[x+1]*(x*2+1);
		}
		else
		{
			ans3+=b[x+1]*(x*2);
			ans3+=a[x+1]*(x*2+1);
		}
	}
	ans=max(ans,ans3);
	printf("%I64d\n",ans);
	return 0;
}