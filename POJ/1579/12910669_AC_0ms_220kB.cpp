#include <stdio.h>
#include <string.h>

int dp[21][21][21];
int fun(int a,int b,int c)//这个越界的处理很巧妙
{
	if(a<=0||b<=0||c<=0)
	{
		return 1;
	}
	else if(a>20||b>20||c>20)
		return dp[20][20][20]=fun(20,20,20);
	else if(dp[a][b][c])
		return dp[a][b][c];
	else if(a<b&&b<c)
		return dp[a][b][c]=fun(a,b,c-1)+fun(a,b-1,c-1)-fun(a,b-1,c);
	else
		return dp[a][b][c]=fun(a-1,b,c)+fun(a-1,b-1,c)+fun(a-1,b,c-1)-fun(a-1,b-1,c-1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		if(a==-1&&b==-1&&c==-1)
			break;
		memset(dp,0,sizeof(dp));
		printf("w(%d, %d, %d) = %d\n",a,b,c,fun(a,b,c));
	}
	return 0;
}

/*耗时：0ms，记录一下w(a,b,c)的值。注意防止越界在第三个判断语句进行返还*/