#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
ll max(ll a,ll b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	ll n,k,m,d;
	while(~scanf("%I64d%I64d%I64d%I64d",&n,&k,&m,&d))
	{
		ll  ans=0;
		for(int i = 1 ; i <= d ; i++)
		{
			if(n/k+1<i)
				break;
			ll mina=n/(i*k);
			ll maxi=n/((i-1)*k+1);
			ll cur=0;
			if(mina<=m)
			{
				if(maxi<=m)
					cur=maxi;
				else
					cur=m;
			}
			while(cur*((i-1)*k+1)>n)
				cur--;
			ans=max(ans,cur*i);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}