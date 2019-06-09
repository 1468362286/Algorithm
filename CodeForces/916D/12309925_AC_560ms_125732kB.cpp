#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef _int64 ll;

const int N = 100010,M=10000010;
const int inf =1e9;
int n,tot,tot2,cnt;
char opt[10];
string s;
map<string,int> mp;
int rt[N],ls[M],rs[M],sum[M],rt2[N];

inline int getid(string s)
{
	if(mp.count(s))
		return mp[s];
	mp[s]=++cnt;
	return cnt;
}

inline void insert(int k,int &nk,int l,int r,int x,int v)
{
	nk=++tot;sum[nk]=sum[k]+v;ls[nk]=ls[k];rs[nk]=rs[k];
	if(l==r)
		return;
	int mid=l+r>>1;
	if(x<=mid)
		insert(ls[k],ls[nk],l,mid,x,v);
	else
		insert(rs[k],rs[nk],mid+1,r,x,v);
}

inline int query(int nk,int l,int r,int x,int y)
{
	if(!nk)
		return 0;
	if(l>=x&&r<=y)
		return sum[nk];
	int mid = l+r>>1;
	int ret = 0;
	if(x<=mid)
		ret+=query(ls[nk],l,mid,x,y);
	if(y>mid)
		ret+=query(rs[nk],mid+1,r,x,y);
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	scanf("%d",&n);
	for( i = 1 ; i <= n ; i++)
	{
		int x,b,c;
		scanf("%s",opt);
		rt[i]=rt[i-1];rt2[i]=rt2[i-1];
		if(opt[0]=='s')
		{
			cin>>s;
			scanf("%d",&x);
			b=getid(s);
			int tmp = query(rt2[i],1,n,b,b);
			if(tmp)
				insert(rt[i],rt[i],1,inf,tmp,-1);
			insert(rt2[i],rt2[i],1,n,b,x-tmp);
			insert(rt[i],rt[i],1,inf,x,1);
		}
		else if(opt[0]=='r')
		{
			cin>>s;
			b=getid(s);
			int tmp=query(rt2[i],1,n,b,b);
			if(tmp)
				insert(rt[i],rt[i],1,inf,tmp,-1);
			insert(rt2[i],rt2[i],1,n,b,-tmp);
		}
		else if(opt[0]=='q')
		{
			cin>>s;
			b=getid(s);
			int tmp = query(rt2[i],1,n,b,b);
			if(tmp==0)
				puts("-1");
			else if(tmp==1)
				puts("0");
			else 
				printf("%d\n",query(rt[i],1,inf,1,tmp-1));
			fflush(stdout);
		}
		else
		{
			scanf("%d",&x);
			rt[i]=rt[i-x-1];
			rt2[i]=rt2[i-x-1];
		}
	}
	return 0;
}