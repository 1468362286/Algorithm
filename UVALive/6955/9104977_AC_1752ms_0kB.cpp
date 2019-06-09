#include <iostream>
using namespace std;
int n,p;
int x[100010],y[100010];

bool check(int a,int b)
{
	int i;
	int cnt = 0;
	for( i = 1 ; i <= n ; i++)
	{
		if((y[i]-y[b])*(x[i]-x[a])==(y[i]-y[a])*(x[i]-x[b]))
			cnt++;
	}
	if(cnt>=(n*p+99)/100)
		return true;
	else
		return false;
}

int main()
{
	int i;
	while(~scanf("%d",&n))
	{
		scanf("%d",&p);
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		int ok = 0;
		for( i = 0 ; i < 200 ; i++)
		{
			int x1 = rand()%n+1;
			int y1 = rand()%n+1;
			if(x1==y1)continue;
			if(check(x1,y1)) ok=1;
		}
		if(ok||n<=2)
			printf("possible\n");
		else
			printf("impossible\n");
		
	}
	return 0;
}