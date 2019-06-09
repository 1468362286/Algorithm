#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 3010;
const int inf = 0x3ffffff;
typedef _int64 ll;
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}
ll a[maxn];
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll solve(ll a,ll b)
{
	int c = gcd(a,b);
	return a/c*b;
}

bool check(ll x,int n)
{
	int i;
	vector<int>ans;
	ans.clear();
	for( i = 2 ; i <= int(sqrt(double(x))) ; i++)
	{
		if(x%i==0)
		{
			ans.push_back(i);
			if(i*i!=x)
			ans.push_back(x/i);
		}
	}
	sort(ans.begin(),ans.end());
	for( i = 0 ; i < n ; i++)
	{
		if(ans[i]!=a[i])
			return false;
	}
	return true;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int t,i,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll maxi=0;
		ll mina=inf;
		for( i = 0 ; i < n ; i++)
			scanf("%I64d",&a[i]),maxi=max(a[i],maxi),mina=min(a[i],mina);
		ll ans=1;
		sort(a,a+n);
		/*
		for( i = 0 ; i < n ; i++)
		{
			ans=solve(ans,a[i]);
		}
		if(ans==maxi)
			ans=ans*mina;
			*/
		ans=maxi*mina;
		if(!check(ans,n))
		{
			cout<<-1<<endl;
			continue;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}