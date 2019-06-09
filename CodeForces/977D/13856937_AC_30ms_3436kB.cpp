#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef _int64 ll;
ll a[110];
ll ans[110],b[110];
int n,flag;
map<ll,int> mymap,vist;

void dfs(ll x,int step)
{
	b[step]=x;
	if(step==n-1)
	{
		memcpy(ans,b,sizeof(b));
		flag=1;
	}
	if(x%3==0)
	{
		if(vist[x/3]!=0)
		{
			ll tmp=x/3;
			vist[tmp]--;
			dfs(tmp,step+1);
			vist[tmp]++;
		}
	}
	if(vist[x*2]!=0)
	{
		ll tmp=x*2;
		vist[tmp]--;
		dfs(tmp,step+1);
		vist[tmp]++;
	}
	return;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%d",&n))
	{
		for( i = 0 ; i < n ; i++)
		{
			scanf("%I64d",&a[i]);
			mymap[a[i]]++;
		}
		for( i = 0 ; i < n ; i++)
		{
			memset(b,0,sizeof(b));
			memset(ans,0,sizeof(ans));
			vist=mymap;
			map<ll,int>::iterator it;
			/*
			for(it=vist.begin();it!=vist.end();it++)
				printf("%I64d ",(*it).first);
				*/
			flag=0;
			dfs(a[i],0);
			if(flag)
				break;
		}
		if(flag)
			for( i = 0 ; i < n ; i++)
				printf("%I64d ",ans[i]);
	}
	return 0;
}