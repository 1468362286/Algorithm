#include <stdio.h>
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
const int maxn = 50010;
const int inf = 0x7fffffff;
struct tree
{
	int l,r;
	int Min,Max;
}segTree[200040];

void build(int i,int l,int r)
{
	segTree[i].l=l;
	segTree[i].r=r;
	segTree[i].Max=0;
	segTree[i].Min=0;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build((i<<1)|1,mid+1,r);
}

void push_up(int i)
{
	segTree[i].Max=max(segTree[i<<1].Max,segTree[(i<<1)|1].Max);
	segTree[i].Min=min(segTree[i<<1].Min,segTree[(i<<1)|1].Min);
}

void updata(int i,int k,int val)
{
	if(segTree[i].l==k&&segTree[i].r==k)
	{
		segTree[i].Max=val;
		segTree[i].Min=val;
		return;
	}
	int mid = (segTree[i].r+segTree[i].l)>>1;
	if(k<=mid)
		updata(i<<1,k,val);
	else
		updata((i<<1)|1,k,val);
	push_up(i);
}

int query1(int i,int l,int r)
{
	if((segTree[i].l==l)&&(segTree[i].r==r))
	{
		return segTree[i].Max;
	}
	int mid = (segTree[i].r+segTree[i].l)>>1;
	if(r<=mid)
		return query1(i<<1,l,r);
	else if(l>mid)
		return query1((i<<1)|1,l,r);
	else 
		return max(query1(i<<1,l,mid),query1((i<<1)|1,mid+1,r));
}

int query2(int i,int l,int r)
{
	if(segTree[i].l==l&&segTree[i].r==r)
	{
		return segTree[i].Min;
	}
	int mid = (segTree[i].r+segTree[i].l)>>1;
	if(r<=mid)
		return query2(i<<1,l,r);
	else if(l>mid)
		return query2((i<<1)|1,l,r);
	else 
		return min(query2(i<<1,l,mid),query2((i<<1)|1,mid+1,r));
}
int nMax,nMin;
void query3(int i,int l,int r)
{
	if(segTree[i].Max<=nMax&&segTree[i].Min>=nMin)
		return;
	if(segTree[i].l==l&&segTree[i].r==r)
	{
		nMax=max(segTree[i].Max,nMax);
		nMin=min(segTree[i].Min,nMin);
		return;
	}
	int mid = (segTree[i].r+segTree[i].l)>>1;
	if(r<=mid)
		query3(i<<1,l,r);
	else if(l>mid)
		query3((i<<1)|1,l,r);
	else 
	{
		query3(i<<1,l,mid);
		query3((i<<1)|1,mid+1,r);
	}

}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,Q,l,r,i,x;
	while(~scanf("%d%d",&n,&Q))
	{
		build(1,1,n);
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&x);
			updata(1,i,x);
		}
		while(Q--)
		{
			scanf("%d%d",&l,&r);
		//	printf("%d\n",query1(1,l,r)-query2(1,l,r));
			nMax=0,nMin=inf;
			query3(1,l,r);
			printf("%d\n",nMax-nMin);
		}
	}
	return 0;
}
/*耗时：3844ms，orz,用一个查询耗时3485ms*/