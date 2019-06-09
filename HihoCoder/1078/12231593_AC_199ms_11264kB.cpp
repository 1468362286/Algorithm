#include <cstdio>
#define maxn 100010
#define lson ((rt)<<1)
#define rson ((rt)<<1|1)

inline int midi(int l,int r){return (l+r)>>1;}

struct node
{
	int l,r,val,len,tag;
}tree[maxn*4];

void lift_up(int rt)
{
	tree[rt].val=tree[lson].val+tree[rson].val;
}

void push_down(int rt)
{
	if(tree[rt].tag)
	{
		tree[lson].val = tree[rt].tag*tree[lson].len;
		tree[rson].val = tree[rt].tag*tree[rson].len;
		tree[lson].tag = tree[rson].tag = tree[rt].tag;
		tree[rt].tag=0;
	}
}

void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].len = r-l+1;
	if(l==r)
	{
		scanf("%d",&tree[rt].val);
		return;
	}
	int mid = midi(l,r);
	build(lson,l,mid);
	build(rson,mid+1,r);
	lift_up(rt);
}

void modify(int rt,int l,int r,int val)
{
	if(tree[rt].l==l&&tree[rt].r==r)
	{
		tree[rt].val = tree[rt].len*val;//只修改了祖先节点并打上lazy tag，表示下面的点还没有修改
		tree[rt].tag = val;
		return;
	}
	push_down(rt);//修改操作，如果有lazy标记就修改，并传下去
	int mid = midi(tree[rt].l,tree[rt].r);
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

int query(int rt,int l,int r)
{
	if(tree[rt].l==l&&tree[rt].r==r)
		return tree[rt].val;
	push_down(rt);
	int mid = midi(tree[rt].l,tree[rt].r);
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
	int n,m;
	scanf("%d",&n);
	build(1,1,n);
	scanf("%d",&m);
	for(int i = 0 ; i < m ; i++)
	{
		int x,l,r;
		scanf("%d",&x);
		if(x==0)
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1,l,r));
		}
		else
		{
			int val;
			scanf("%d%d%d",&l,&r,&val);
			modify(1,l,r,val);
		}
	}
	return 0;
}

/*耗时：202ms*/