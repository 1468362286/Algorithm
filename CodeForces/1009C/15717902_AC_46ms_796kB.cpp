#include <iostream>
#include <string>
using namespace std;
const int maxn = 100010;
double a[maxn];
typedef _int64 ll;
int main()
{
	//freopen("in.txt","r",stdin);
	ll n;
	int i,m;
	ll x,d;
	while(~scanf("%I64d%d",&n,&m))
	{
		//memset(a,0,sizeof(a));
		ll sum=0;
		for( i = 0 ; i < m ; i++)
		{
			scanf("%I64d%I64d",&x,&d);
			if(d>=0)
			{
				/*
				for( j = 1 ; j <= n ; j++)
				{
					a[j]+=x+d*abs(j-1);	
				}
				*/
				sum+=n*x+d*(n-1)*n/2;
			}
			else
			{
				/*
				for( j = 1 ; j <= n ; j++)
				{
					a[j]+=x+d*abs(j-n/2);	
				}*/
				if(n%2==0)
					sum+=n*x+d*(n/2)*(n/2);
				else
					sum+=n*x+d*(1+n/2)*(n/2);
			}
		}
		/*
		for( i = 1 ; i <= n ; i++)
		{
			sum+=a[i];
		}*/
		printf("%.6lf\n",1.0*sum/n);
	}
	return 0;
}