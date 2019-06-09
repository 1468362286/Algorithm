#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
//#include <unordered_map>
using namespace std;
typedef _int64 ll;
//unordered_map<ll,ll> mp;
map<ll,ll> mp;

inline ll lca(ll v,ll u ,ll w=-1)
{
	ll ans = 0;
	while(v!=u)
	{
		if(v<u)
			swap(v,u);
		if(mp.find(v)!=mp.end())
			ans+=mp[v];
		if(~w)
			mp[v]+=w;
		v>>=1;
	}
	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int q;
	cin>>q;
	while(q--)
	{
		int type;
		ll v,u;
		scanf("%d%I64d%I64d",&type,&v,&u);
		if(type==1)
		{
			ll w;
			scanf("%I64d",&w);
			lca(v,u,w);
		}
		else
			printf("%I64d\n",lca(v,u));
	}
	return 0;
}