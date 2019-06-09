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
int flag;
ll path[maxn];
ll ans[maxn];
int anslen;
void dfs(ll a,ll b,int step)
{
	if(flag)return;
	path[step]=a;
	if(a>=b)
	{
		if(a==b)
		{
			flag=1;
			anslen=step;
			for(int i = 1 ; i <= step ; i++)
				ans[i]=path[i];
		}
		return;
	}
	dfs(2*a,b,step+1);
	dfs(10*a+1,b,step+1);
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	ll a,b;
	while(~scanf("%I64d%I64d",&a,&b))
	{
		flag=0;
		dfs(a,b,1);
		if(flag)
		{
			cout<<"YES"<<endl<<anslen<<endl;
			for(int i = 1 ; i <= anslen ; i++)
				printf("%I64d ",ans[i]);
			printf("\n");
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}