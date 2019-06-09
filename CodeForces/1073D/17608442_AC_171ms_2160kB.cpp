#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;
typedef _int64 ll;
const int maxn = 200010;
const ll inf = 0x7fffffff;

ll min(ll a,ll b){return a>b?b:a;}
vector<int>vec;
int a[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	ll T;
	while(~scanf("%d%I64d",&n,&T))
	{
		ll sum=0;
		ll cnt=0;
		ll mina=inf;
		vec.clear();
		int flag=0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
			mina=min(a[i],mina);
		}
		for( i = 0 ; i < n ; i++)
		{
			if(a[i]<=T)
			{
				sum+=a[i];
				T-=a[i];
				cnt++;
				vec.push_back(a[i]);
			}
		}
		if(T<mina)
		{
			printf("%I64d\n",cnt);
		}
		else
		{
			cnt += (T/sum)*vec.size();
			ll tmp=T%sum;
			ll s = 0;
			while(tmp>=mina)
			{
				ll tm=0,su=0;
				for( i = 0 ; i < vec.size() ; i++)
				{
					if(tmp>=vec[i])
						tmp-=vec[i],tm++,su+=vec[i];
				}
				cnt+=(tmp/su+1)*tm;
				tmp%=su;
			}
			printf("%I64d\n",cnt);
		}	
	}
	return 0;
}