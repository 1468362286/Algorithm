#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
typedef _int64 ll;
const int maxn = 150000+100;
ll a[maxn],b[maxn];
ll __gcd(ll a,ll b){return a==0?b:__gcd(b%a,a);}
int main()
{
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			scanf("%I64d %I64d",&a[i],&b[i]);
		}
		ll gcd=a[0]*b[0]/__gcd(a[0],b[0]);
		for( i = 1 ; i < n ; i++)
			gcd=__gcd(gcd,a[i]*b[i]/__gcd(a[i],b[i]));
		if(gcd==1)
		{
			printf("-1\n");
			continue;
		}
		ll temp;
		for( i = 0 ; i < n ; i++)
		{
			temp=__gcd(gcd,a[i]);
			if(temp>1)
				gcd=temp;
			temp=__gcd(gcd,b[i]);
			if(temp>1)
				gcd=temp;
		}
		printf("%I64d\n",gcd);
	}
	return 0;
}