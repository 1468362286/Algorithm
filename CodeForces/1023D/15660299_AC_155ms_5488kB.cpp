#include <iostream>
#include <string>
using namespace std;
const int maxn = 200000+100;
int n,q;
int num[maxn],L[maxn],R[maxn];
int Min[maxn<<2];
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
void push_up(int rt)
{
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		Min[rt]=num[l];
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	push_up(rt);
}

void update(int x,int l,int r,int rt)
{
	if(l==r)
	{
		Min[rt]=x;
		num[l]=x;
		return;
	}
	int m=(l+r)>>1;
	if(Min[rt<<1]==0)
	{
		update(x,l,m,rt<<1);
	}
	if(Min[rt<<1|1]==0)
	{
		update(x,m+1,r,rt<<1|1);
	}
	push_up(rt);
}

int query(int L,int R,int x,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		if(Min[rt]==0)
			update(x,l,r,rt);
		return Min[rt];
	}
	int m=(l+r)>>1;
	int ret=INT_MAX;
	if(L<=m)
		ret=min(ret,query(L,R,x,l,m,rt<<1));
	if(m<R)
		ret=min(ret,query(L,R,x,m+1,r,rt<<1|1));
	push_up(rt);
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%d%d",&n,&q))
	{
		for( i = 0 ; i <= q ; i++)
		{
			L[i]=n+1;
			R[i]=0;
		}
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&num[i]);
			L[num[i]]=min(L[num[i]],i);
			R[num[i]]=max(R[num[i]],i);
		}
		if(L[q]>R[q])
		{
			if(L[0]!=n+1)
			{
				num[L[0]]=q;
				L[q]=R[q]=L[0];
			}
			else
			{
				printf("NO\n");
				continue;
			}
		}
		build(1,n,1);
		bool flag=true;
		for( i = q ; i >= 1 ; i--)
		{
			if(L[i]>R[i])
				continue;
			if(query(L[i],R[i],i,1,n,1)<i)
			{
				flag=false;
				break;
			}
		}
		if(!flag)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for( i = 1 ; i <= n ; i++)
		{
			if(i!=1)
				printf(" ");
			if(num[i]==0)
				printf("1");
			else
				printf("%d",num[i]);
		}
		printf("\n");
	}
	return 0;
}
