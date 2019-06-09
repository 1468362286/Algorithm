#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
//#include <unique>
#include <vector>
using namespace std;
const int maxn = 200005;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int n,cnt;
int a[maxn],dp[maxn];
int head[maxn];
vector<int>vec[maxn];

template <class T>
static T amax(T a,T b)
{
	return a>b?a:b;
}
struct node
{
	int v,next;
}e[maxn*2];

void add(int u,int v)
{
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u]=cnt++;
}

void dfs(int u,int pre)
{
    for(int i=head[u];~i;i=e[i].next)
    {
        int v=e[i].v;
        if(v==pre) continue;
        dp[v]=gcd(dp[u],a[v]);
        vec[v].push_back(dp[u]);   //不改变当前节点值的情况
        for(int j=0;j<vec[u].size();j++)
        {
            vec[v].push_back(gcd(vec[u][j],a[v]));
        }
        sort(vec[v].begin(),vec[v].end());                     //排序去重
        vec[v].erase(unique(vec[v].begin(),vec[v].end()),vec[v].end());
        dfs(v,u);
    }
}

int main()
{
	//freopen("in.txt","r",stdin);
	int x,y,i;
	while(~scanf("%d",&n))
	{
		memset(head,-1,sizeof(head));
	//	memset(dp,1,sizeof(dp));
		cnt = 0;
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&a[i]);
	//		vec[i].clear();
		}
		for( i = 0 ; i <n-1 ; i++)
		{
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dp[1]=a[1];
		vec[1].push_back(0);
		dfs(1,-1);
		for( i = 1 ; i <= n ; i++)
		{
			dp[i] = amax(dp[i],vec[i].back());
		}
		for( i = 1 ; i < n ; i++)
		{
			printf("%d ",dp[i]);
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
