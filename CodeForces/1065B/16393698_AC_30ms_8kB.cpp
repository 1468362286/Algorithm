#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
ll max(ll a,ll b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	ll n,m;
	ll i;
	while(~scanf("%I64d%I64d",&n,&m))
	{
		for( i = 1 ; i <= n ; i++)
		{
		//	ll tmp = i*(i-1)/2;
			if(i*(i-1)/2>=m)
				break;
		}
//		cout<<max(0,n-2*m)<<" "<<(n-i)<<endl;
		printf("%I64d %I64d\n",max(0,n-2*m),m==0?n:n-i);
	}
	return 0;
}