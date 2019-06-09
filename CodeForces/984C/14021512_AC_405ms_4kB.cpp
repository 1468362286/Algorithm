#include <iostream>
#include <string>
using namespace std;

typedef _int64 ll;

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

int main()
{
	//freopen("in.txt","r",stdin);
	ll p,q,b,g;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d%I64d",&p,&q,&b);
		q/=gcd(p,q);
		g=b;
		while(q!=1)
		{
			g=gcd(g,q);
			if(g==1)
				break;
			while(q%g==0)
				q/=g;
		}
		printf("%s\n",q==1?"Finite":"Infinite");
	}
	return 0;
}