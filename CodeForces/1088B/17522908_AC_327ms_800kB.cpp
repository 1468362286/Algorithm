#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>
using namespace std;
typedef _int64 ll;
const int maxn = 100010;
const int inf = 0x3f3f3f3f;
ll min(ll a,ll b){return a>b?b:a;}
ll a[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,q,i;
	while(cin>>n>>q)
	{
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%I64d",&a[i]);
		}
		sort(a+1,a+n+1);
		int p = 1;
		ll sum=0;
		while(q--)
		{
			int flag=0;
			for( i = p ; i <= n ; i++)
			{
				a[i]-=min(sum,a[i]);
				if(a[i]>0)
				{
					printf("%I64d\n",a[i]);
					p=i+1;
					sum+=a[i];
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				for( i = 0 ; i <= q ; i++)
					cout<<"0"<<endl;
				break;
			}
		}
	}
	return 0;
}