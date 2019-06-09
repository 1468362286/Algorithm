#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
const int maxn = 2010;
const int inf=0x3f3f3f3f;
ll a[maxn],b[maxn],ma[maxn],mb[maxn];
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
int main()
{	
	//freopen("in.txt","r",stdin);
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	a[0]=b[0]=0;
	for( i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
		a[i]+=a[i-1];
	}
	for( i = 1 ; i <= m ; i++)
	{
		scanf("%I64d",&b[i]);
		b[i]+=b[i-1];
	}
	memset(ma,inf,sizeof(ma));
	memset(mb,inf,sizeof(mb));
	for( i = 1 ; i <= n ; i++)
		for( j = i ; j <= n ; j++)
			ma[j-i+1]=min(ma[j-i+1],a[j]-a[i-1]);
	for( i = 1 ; i <= m ; i++)
		for( j = i ; j <= m ; j++)
			mb[j-i+1]=min(mb[j-i+1],b[j]-b[i-1]);
	ll x;
	scanf("%I64d",&x);
	int ans=0;
	for( i = 1 ; i <= n ; i++)
		for( j = 1 ; j <= m ; j++)
			if(ma[i]*mb[j]<=x)
				ans=max(ans,i*j);
	printf("%d\n",ans);
	return 0;
}