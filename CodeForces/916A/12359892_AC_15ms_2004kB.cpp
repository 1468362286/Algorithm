#include <stdio.h>
#include <string.h>
int change(char X[])
{
	int flag = 0;
	int ans = 0;
	for(int i = 0 ; i < strlen(X) ; i++)
	{
		if(X[i]==0&&!flag)
			flag=1;
		else
		{
			ans = ans*10+X[i]-'0';
		}
	}
	return ans;
}

bool check(int x)
{
	while(x)
	{
		if((x%10)==7)
			return true;
		x/=10;
	}
	return false;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int x,ans;
	char H[3],M[3];
	while(~scanf("%d",&x))
	{
		scanf("%s%s",&H,&M);
		int h=change(H);
		int m=change(M);
		int cnt = 0,sum=0;
		while(1)
		{
			if(check(h)||check(m))
			{
				ans = cnt;
				break;
			}
			sum = h*60+m;
			sum-=x;
			if(sum<0)
			{
				sum+=24*60;
			}
			h = sum/60;
			m = sum%60;
			cnt++;
		}
		printf("%d\n",ans);
	}
	return 0;
}