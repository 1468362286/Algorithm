#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
#include <numeric>
using namespace std;
const int maxn = 300010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
double min(double a,double b){return a>b?b:a;}
typedef _int64 ll;
#define x first
#define y second
ll a[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			scanf("%I64d",&a[i]);
		sort(a,a+n);
		ll ans=0;
		for( i = 0 ; i < n/2 ; i++)
			ans+=(a[i]+a[n-1-i])*(a[i]+a[n-1-i]);
		printf("%I64d\n",ans);
	}
	return 0;
}