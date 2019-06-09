#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef _int64 ll;
const int maxn = 100010;
ll fa[maxn];
ll a[maxn];
int vist[maxn];
priority_queue<ll,vector<ll>,greater<ll> > p[maxn];
template<class T>
static T Min(T A,T B)
{
	return A>B?B:A;
}

ll find(ll x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
/*
ll find(ll x)
{
	if(x==fa[x])
		return x;
	else
	{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
*/
void unix(ll x,ll y)
{
	ll fx = find(x);
	ll fy = find(y);
	if(fx!=fy)
	{
		fa[fy]=fx;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	ll n,m,i,x,y;
	while(~scanf("%I64d%I64d",&n,&m))
	{
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%I64d",&a[i]);
			vist[fa[i]]=0;
			fa[i]=i;
			/*
			while(!p[fa[i]].empty())
				p[fa[i]].pop();
				*/
		}
		for( i = 0 ; i < m ; i++)
		{
			scanf("%I64d%I64d",&x,&y);
			unix(x,y);
		}
		ll ans = 0;
		
		for( i = 1 ; i <= n ; i++)
		{
			ll fx = find(i);
			p[fx].push(a[i]);
		}
		for( i = 1 ; i <= n ; i++)
		{
			ll fx = find(i);
			if(!p[fx].empty()&&!vist[fx])
			{
				ll tmp = p[fx].top();
				ans+=tmp;
				vist[fx]=1;
			}
		}
		
		/*
		for( i = 1 ; i <= n ; i++)
			a[find(i)]=Min(a[find(i)],a[i]);
		for( i = 1 ; i <= n ; i++)
			if(i==find(i))
				ans+=a[i];
				*/
		printf("%I64d\n",ans);
		
	}
	return 0;
}

/*是我sb了，如果那么直接写find函数为ll find(ll x)
{
	return x==fa[x]?x:find(fa[x]);
}
这样就没有使得fa[x]=x，没有赋值给它。
*/