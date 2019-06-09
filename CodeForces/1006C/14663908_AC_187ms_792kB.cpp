#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 200010;
typedef _int64 ll;
ll max(ll a,ll b){return a>b?a:b;}
int a[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		int l = 0,r = n-1;
		ll suml=a[l],sumr=a[r];
		ll ans=0;
		while(l<r)
		{
			if(suml==sumr)
			{
				ans = max(ans,suml);
		//		sumr+=a[++l];
				suml+=a[++l];
			}
			else if(suml>sumr)
			{
				sumr+=a[--r];
			}
			else if(suml<sumr)
			{
				suml+=a[++l];
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}