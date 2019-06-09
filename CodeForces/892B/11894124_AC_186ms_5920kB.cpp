#include <stdio.h>
const int maxn = 1000010;
int a[maxn];
int max(int a,int b){return a>b?a:b;}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,cnt;
	while(~scanf("%d",&n))
	{
		int ans = 1;
		for( i = 0 ; i < n ; i++)
			scanf("%d",a+i);
		cnt = a[n-1];
		for( i = n-2 ; i >= 0 ; i--)
		{
			if(n-1-cnt>i)
				ans++;
			cnt=max(cnt,a[i]+n-1-i);
		}
		printf("%d\n",ans);
	} 
	return 0;
}