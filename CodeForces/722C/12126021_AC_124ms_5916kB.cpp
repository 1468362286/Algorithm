#include <stdio.h>
#include <string.h>
typedef _int64 ll;
#define lowbit(x) (x&(-x))
const int maxn = 100010;
ll sum[maxn],a[maxn],ans[maxn],h[maxn];
int b[maxn],fa[maxn];
template <class T> static T Max(T a,T b){return a>b?a:b;}
int find(int x){return fa[x]==x?x:find(fa[x]);}

void unix(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	sum[fx]+=sum[fy];
	fa[fy] = fx;
}

void update(int x,int n)
{
	int lx,i;
	while(x<=n)
	{
		h[x] = sum[x];
		lx = lowbit(x);
		for( i = 1 ; i < lx ; i<<=1)
		{
			h[x] = Max(h[x],h[x-i]);
		}
		x+=lowbit(x);
	}
}

ll query(int x,int y)
{
	ll ans = 0;
	while(y>=x)
	{
		ans = Max(sum[y],ans);
		y--;
		for(;y-lowbit(y)>=x;y-=lowbit(y))
		{
			ans = Max(h[y],ans);
		}
	}
	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ; i++)
			scanf("%I64d",&a[i]);
		for( i = 1 ; i <= n ; i++)
			scanf("%d",&b[i]);
		memset(fa,-1,sizeof(fa));
		memset(sum,0,sizeof(sum));
		for( i = n ; i >= 1 ; i--)
		{
			ans[i] = query(1,n);
			int id = b[i];
			sum[id] = a[id];
			fa[id] = id;
			if(fa[id-1]!=-1)
				unix(id-1,id);
			if(fa[id+1]!=-1)
				unix(id,id+1);
			int fid = find(id);
				update(fid,n);
		}
		for( i = 1; i <= n ; i++)
			printf("%I64d\n",ans[i]);
	}
	return 0;
}