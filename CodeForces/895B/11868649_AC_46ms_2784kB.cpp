#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef _int64 ll;
const int maxn = 100010;
ll a[maxn];
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	ll n,x,k;
	while(~scanf("%I64d%I64d%I64d",&n,&x,&k))
	{
		ll sum = 0;
		for( i = 0 ; i < n ; i++)
			scanf("%I64d",a+i);
		sort(a,a+n);
		for( i = 0 ; i < n ; i++)
		{
			ll tmp = ceil(a[i]*1.0/x)*x;
			/*
			ll tmp = 0 ;
			while(tmp<a[i])
			{
				tmp+=x;
			}
			*/
		//	tmp+=x*k;
			sum+=lower_bound(a,a+n,tmp+k*x)-lower_bound(a,a+n,max(a[i],tmp+(k-1)*x));
		}
		printf("%I64d\n",sum);
	}
	return 0;
}