#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;
typedef _int64 ll;
const int maxn = 100010;
int a[maxn];
ll pre[maxn];
ll pre1[maxn];
map<ll,int> mymap;
template<class T> static T Max(T a,T b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		memset(pre,0,sizeof(pre));
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&a[i]);
			pre[i]=pre[i-1]+a[i];
			mymap[pre[i]]++;
		}
		int maxi=0;
		for( i = 1 ; i <= n ; i++)
		{
			maxi=Max(mymap[pre[i]],maxi);
		}
		printf("%d\n",n-maxi);
	}
	return 0;
}