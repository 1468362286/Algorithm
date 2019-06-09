#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 2000010;
int max(int a,int b){return a>b?a:b;}
struct node
{
	int lson,rson,cnt;
	void init()
	{
		lson=rson=-1;
		cnt=0;
	}
}q[maxn];
int root[maxn],tot;

void add(int &rt,int l,int r,int val,int cnt)
{
	if(rt==-1)
	{
		rt=tot++;
		q[rt].init();
	}
	q[rt].cnt=max(q[rt].cnt,cnt);
	if(l==r)return;
	int mid=(l+r)>>1;
	if(val<=mid)add(q[rt].lson,l,mid,val,cnt);
	else add(q[rt].rson,mid+1,r,val,cnt);
}

int query(int rt,int l,int r,int x,int y)
{
	if(rt==-1)return 0;
	if(x<=l&&r<=y)return q[rt].cnt;
	int mid=(l+r)>>1;
	int ret=0;
	if(x<=mid) ret=max(ret,query(q[rt].lson,l,mid,x,y));
	if(y>=mid+1) ret=max(ret,query(q[rt].rson,mid+1,r,x,y));
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		tot=0;
		memset(root,-1,sizeof(root));
		int ans=0;
		for(int i = 1 ; i <= m ; i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			int max_cnt=query(root[u],-1,100000,-1,w-1);
			ans=max(ans,max_cnt+1);
			add(root[v],-1,100000,w,max_cnt+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}