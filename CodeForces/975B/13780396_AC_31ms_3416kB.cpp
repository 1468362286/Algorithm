#include <iostream>
#include <string>
#include <string.h>
using namespace std;
typedef _int64 ll;
_int64 a[14],b[14];
inline ll max(ll a,ll b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	_int64 i,j;
	for( i = 0 ; i < 14 ; i++)
	{
		scanf("%I64d",&a[i]);
	}
	_int64 maxi=0;
	for( i = 0 ; i < 14 ; i++)
	{
		memcpy(b,a,sizeof(a));
		int tmp=b[i];
		b[i]=0;	
		int g=tmp/14;
		for( j = 0 ; j < 14 ; j++)
		{
			b[j]+=g;
		}
		tmp=tmp%14;
		for( j = i+1 ; j<=i+tmp ; j++)
		{
			int p=j%14;
			b[p] = b[p]+1;
		}
		_int64 ans=0;
		for( j = 0 ; j < 14 ; j++)
		{
			if(!(b[j]&1))
				ans+=b[j];
		}
		maxi=max(ans,maxi);
	}
	printf("%I64d\n",maxi);
	return 0;
}