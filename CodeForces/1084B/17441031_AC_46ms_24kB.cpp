#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
typedef _int64 ll;
const int maxn = 1010;
ll a[maxn];
bool cmp(ll a,ll b){return a>b;}
ll min(ll a,ll b){return a>b?b:a;}
int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	ll s,n;
	while(~scanf("%I64d%I64d",&n,&s))
	{
		for( i = 0 ; i < n ; i++)
		{
			scanf("%I64d",&a[i]);
		}
		int flag=0;
		while(s)
		{
			sort(a,a+n,cmp);
			if(a[0]==0)
			{
				flag=1;
				break;
			}
			if(a[0]==a[n-1])
			{
				a[n-1]-=s/n+(s%n==0?0:1);
				break;
			}
			s-=min((a[0]-a[n-1]),s);
			a[0]=a[n-1];
		}
		sort(a,a+n,cmp);
		if(flag||a[n-1]<0)cout<<"-1"<<endl;
		else printf("%I64d\n",a[n-1]);
	}
	return 0;
}