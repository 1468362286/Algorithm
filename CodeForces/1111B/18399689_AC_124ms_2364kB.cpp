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
const int maxn = 100010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
double min(double a,double b){return a>b?b:a;}
typedef _int64 ll;
#define x first
#define y second
double a[maxn];
double pre_sum[maxn];
double f[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,k,m,i;
	while(cin>>n>>k>>m)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for( i = 1 ; i <= n ; i++)
			pre_sum[i]=pre_sum[i-1]+a[i];
		for( i = 0 ; i <= min(m,n-1) ; i++)
		{
			f[i]=(pre_sum[n]-pre_sum[i]+min(1.0*(m-i),1.0*k*(n-i)))/(n-i);
		}
		double ans=0;
		for( i = 0 ; i <= min(m,n-1) ; i++)
			if(ans<f[i])ans=f[i];
		printf("%.6lf\n",ans);
	}
	return 0;
}