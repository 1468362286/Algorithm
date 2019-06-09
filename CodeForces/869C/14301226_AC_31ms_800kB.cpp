#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
const int maxn = 50010;
const int mod = 998244353;
inline int min(int a,int b){return a>b?b:a;}
ll mul[maxn];
ll inv[maxn];

void init()
{
	int i;
	mul[0]=1;
	for( i = 1 ; i < maxn ; i++)
		mul[i]=(mul[i-1]*i)%mod;
	inv[0]=inv[1]=1;
	for( i = 2 ; i < maxn ; i++)
		inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for( i = 1 ; i < maxn ; i++)
		inv[i]=(inv[i-1]*inv[i])%mod;
}

ll C(int n,int m)
{
	return mul[n]*inv[m]%mod*inv[n-m]%mod;
}

ll mult(int a,int b)
{
	int len=min(a,b);
	ll ans=0;
	for(int i = 0 ; i <= len ; i++)
		ans+=C(a,i)*C(b,i)%mod*mul[i]%mod,ans%=mod;
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
	init();
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		ll ans=mult(a,b)*mult(b,c)%mod*mult(c,a)%mod;
		printf("%I64d\n",ans);
	}
	return 0;
}