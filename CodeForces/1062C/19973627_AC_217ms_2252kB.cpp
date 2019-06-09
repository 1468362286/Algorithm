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
const int maxn = 500010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
const int mod = 1e9+7;
int pre_sum[maxn];

ll quick_pow(ll a,ll b)
{
	ll sum=1;
	while(b)
	{
		if(b&1)sum=(sum*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return sum;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,q,l,r,i,cnt1,cnt0;
	string s,tmp;
	while(cin>>n>>q)
	{
		s=" ";
		cin>>tmp;
		s+=tmp;
		int cnt=0;
		for( i = 1 ; i < s.size() ; i++)
		{
			if(s[i]=='1')
			{
				cnt++;
			}
			pre_sum[i]=cnt;
		}
		while(q--)
		{
			cin>>l>>r;
			cnt1=pre_sum[r]-pre_sum[l-1];
			cnt0=r-l+1-cnt1;
			ll ans=((quick_pow(2,cnt1)-1)*quick_pow(2,cnt0))%mod;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}