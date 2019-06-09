#include <iostream>
#include <string>
#include <string.h>
using namespace std;
typedef _int64 ll;
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a>b?b:a;}

ll cdiv(ll a,ll b)
{
	return a/b+(a%b>0);
}
ll ccdiv(ll a,ll b)
{
	return (a+b-1)/b;
}
ll w(ll x,ll y)
{
	return cdiv(x,2)*cdiv(y,2)+(x/2)*(y/2);
}
ll wsum(ll x1,ll y1,ll x2,ll y2)
{
	return w(x2,y2)-w(x1-1,y2)-w(x2,y1-1)+w(x1-1,y1-1);
}
ll bsum(ll x1,ll y1,ll x2,ll y2)
{
	return (x2-x1+1)*(y2-y1+1)-wsum(x1,y1,x2,y2);
}
int main()
{
	//freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m,w,b,x1,x2,x3,x4,y1,y2,y3,y4;
		scanf("%I64d%I64d",&n,&m);
		scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2);
		scanf("%I64d%I64d%I64d%I64dd",&x3,&y3,&x4,&y4);
		w = wsum(1,1,m,n);
		b = bsum(1,1,m,n);

		w+=bsum(x1,y1,x2,y2);
		b-=bsum(x1,y1,x2,y2);
		
		w-=wsum(x3,y3,x4,y4);
		b+=wsum(x3,y3,x4,y4);
		if(max(x1,x3)<=min(x2,x4)&&max(y1,y3)<=min(y2,y4))
		{
			w-=bsum(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4));
			b+=bsum(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4));
		}
		printf("%I64d %I64d\n",w,b);
	}
	return 0;
}