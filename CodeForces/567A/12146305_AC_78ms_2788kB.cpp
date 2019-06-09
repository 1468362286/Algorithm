#include <stdio.h>
typedef _int64 ll;
const int maxn =100010;
ll a[maxn];

template<class T> static T Max(T a,T b){return a>b?a:b;}
template<class T> static T Min(T a,T b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		for( i = 0 ; i < n ; i++)
		{
			scanf("%I64d",a+i);
		}
		for( i = 0 ; i < n ; i++)
		{
			ll mina = 2147483648;
			ll maxi = -1;
			if(i>0)
			{
				mina = a[i]-a[i-1];
				maxi = a[i]-a[0];
			}
			if(i<n-1)
			{
				mina = Min(mina,a[i+1]-a[i]);
				maxi = Max(maxi,a[n-1]-a[i]);
			}
			printf("%I64d %I64d\n",mina,maxi);
		}
	}
	return 0;
}