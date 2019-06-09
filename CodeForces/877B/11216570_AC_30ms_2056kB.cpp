#include <stdio.h>
#include <string.h>
char s[5005];

int a_sum[5005];
int b_sum[5005];
int n;
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%s",s+1))
	{
		n = strlen(s+1);
		for( i = 1 ; i < n+3 ; i++)
		{
			a_sum[i] = a_sum[i-1]+(s[i]=='a');
			b_sum[i] = b_sum[i-1]+(s[i]=='b');
		}
		int ans = 0;
		for( i = 0 ; i <= n ; i++)
			for( j = i+1 ; j <=(n+1) ; j++)
			{
				int a = a_sum[i];
				int b = b_sum[j-1]-b_sum[i];
				int c = a_sum[n+1]-a_sum[j-1];
				ans = max(ans,a+b+c);
			}
		printf("%d\n",ans);
	}
	return 0;
}