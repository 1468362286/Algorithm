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
const int maxn = 100010;
const int inf = 0x3ffffff;
typedef long long ll;
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	ll l1,r1,l2,r2,k,ans;
	while(cin>>l1>>r1>>l2>>r2>>k)
	{
		ll L = max(l1,l2);
		ll R = min(r1,r2);
		if(L<=R)
		{
			if(k>=L&&k<=R)
			{
				ans=R-L;
			}
			else
				ans=R-L+1;
			cout<<ans<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}