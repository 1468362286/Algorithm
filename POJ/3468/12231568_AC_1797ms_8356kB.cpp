#include <cstdio>
#define maxn 100010
#define lson (rt<<1)
#define rson ((rt<<1)|1)
typedef long long ll;

struct Tree
{
	int l,r,len;
	ll val,tag;
}tree[maxn*4];

int midd(int l,int r){return (l+r)>>1;}

void lift_up(int rt)
{
	tree[rt].val=tree[lson].val+tree[rson].val;
}

void push_down(int rt)
{
	if(tree[rt].tag)
	{
		ll tag = tree[rt].tag;
		tree[lson].tag+=tag;
		tree[rson].tag+=tag;
		tree[lson].val+=tree[rt].tag*tree[lson].len;
		tree[rson].val+=tree[rt].tag*tree[rson].len;
		tree[rt].tag=0;
	}
}

void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].len = r-l+1;
	if(r==l)
	{
		scanf("%lld",&tree[rt].val);
		return;
	}
	int mid = midd(l,r);
	build(lson,l,mid);
	build(rson,mid+1,r);
	lift_up(rt);
}

void modify(int rt,int l,int r,ll val)
{
	if(tree[rt].l==l&&tree[rt].r==r)
	{
		tree[rt].val+=ll(tree[rt].len*val);
		tree[rt].tag += val;
		return;
	}
	push_down(rt);
	int mid = midd(tree[rt].l,tree[rt].r);
	if(r<=mid)
		modify(lson,l,r,val);
	else if(l>mid)
		modify(rson,l,r,val);
	else 
	{
		modify(lson,l,mid,val);
		modify(rson,mid+1,r,val);
	}
	lift_up(rt);
}

ll query(int rt,int l,int r)
{
	if(tree[rt].l==l&&tree[rt].r==r)
	{
		return tree[rt].val;
	}
	push_down(rt);
	int mid = midd(tree[rt].l,tree[rt].r);
	if(r<=mid)
		return query(lson,l,r);
	else if(l>mid)
		return query(rson,l,r);
	else
		return query(lson,l,mid)+query(rson,mid+1,r);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,q,l,r,val;
	char ch[2];
	while(~scanf("%d%d",&n,&q))
	{
		build(1,1,n);
		for(int i = 0 ; i < q ; i++)
		{
			scanf("%s",ch);
			if(ch[0]=='C')
			{
				scanf("%d%d%d",&l,&r,&val);
				modify(1,l,r,val);
			}	
			else if(ch[0]=='Q')
			{
				scanf("%d%d",&l,&r);
				printf("%lld\n",query(1,l,r));
			}
		}
	}
	return 0;
}