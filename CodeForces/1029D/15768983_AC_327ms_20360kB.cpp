#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
const int N=200000+10;
int n;
int cnt[12];
ll k;
ll p[12][N];
ll a[N];
int main()
{
	scanf("%d%I64d",&n,&k);
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		ll t=a[i]*10;
		for(int j=1;j<=10;j++)
		{
			p[j][cnt[j]++]=t%k;
			t*=10;
		}
	}
	for(int i=1;i<=10;i++)
		sort(p[i],p[i]+cnt[i]);
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		int q=0;
		ll t=a[i];
		while(t)
		{
			q++;
			t/=10;
		}
		ll z=k-a[i]%k;
		z%=k;
		if(binary_search(p[q],p[q]+cnt[q],z))
		{
			int r=upper_bound(p[q],p[q]+cnt[q],z)-p[q];
			int l=lower_bound(p[q],p[q]+cnt[q],z)-p[q];
			ans+=r-l;
		}
		t=a[i];
		while(q--)
			t*=10;
		if((t+a[i])%k==0) ans--;
	}
	cout<<ans<<endl;
	return 0;
}