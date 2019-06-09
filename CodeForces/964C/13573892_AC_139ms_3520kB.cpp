#include <stdio.h>
#include <string.h>
typedef _int64 ll;
ll mod=1e9+9;
ll find(ll a,ll t)
{
	ll res=1;
	while(t)
	{
		if(t&1)
			res=res*a%mod;
		a=(a*a)%mod;
		t/=2;
	}
	return (res+mod)%mod;
}

ll ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	ll te=ex_gcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-(a/b)*x;
	return te;
}
ll NY(ll nu)
{
	ll x,y;
	ex_gcd(nu,mod,x,y);
	return (x+mod)%mod;
}
char ch[100010];
int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	ll n,a,b,k;
	scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&k);
	scanf("%s",ch);
	ll ans=0,m=(n+1)/k;
	for( i = 0 ; i < k ; i++)
	{
		ll t1=find(a,n-i),t2=find(b,i);
		ll temp=t1*t2%mod;
		if(ch[i]=='+')
			ans+=temp;
		else
			ans-=temp;
		ans+=mod;
		ans%=mod;
	}
	ll q=find(NY(a),k)*find(b,k)%mod;
	if(q==1)
		ans=ans*m%mod;
	else
	{
		ll t1=NY(q-1)%mod;
		ans=(ans*(find(q,m)-1)%mod)*t1%mod;
		ans%=mod;
	}
	ans=(ans+mod)%mod;
	printf("%I64d\n",ans);
	return 0;
}