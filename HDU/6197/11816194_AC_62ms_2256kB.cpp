#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn],c[maxn];
//int dp1[maxn];
//int dp2[maxn];
int max(int a,int b){return a>b?a:b;}

int main()
{
	//freopen("in.txt","r",stdin);
	int T,i,j,n,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for( i = 0 ; i < n ; i++)
			scanf("%d",a+i);
		int cnt=0,ans=0;
		for( i = 0 ; i < n ; i++)
		{
			int p = upper_bound(c,c+cnt,a[i])-c;
			if(p==cnt)
			{
				c[cnt++] = a[i];
				ans = max(ans,cnt);
			}
			else
			{
				c[p] = a[i];
			}
		}
		cnt = 0;
		for( i = n-1 ; i >= 0 ; i--)
		{
			int p = upper_bound(c,c+cnt,a[i])-c;
			if(p==cnt)
			{
				c[cnt++]=a[i];
				ans = max(ans,cnt);
			}
			else
			{
				c[p] = a[i];
			}
		}
		if(ans>=n-k)
			printf("A is a magic array.\n");
		else
			printf("A is not a magic array.\n");
	}
	return 0;
}
