#include <stdio.h>
#include <algorithm>
using namespace std;
int team[300];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,a,b,i,j;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		if(a>b)swap(a,b);
		for( i = 1 ; i <= n ; i++)
			team[i]=i;
		int cnt=0;
		int tmp=n;
		while(tmp>1)
		{
			tmp>>=1;
			cnt++;
		}
		int pp=0;
		while(1)
		{
			pp++;
			for( i = 1 ; i <= n ; i+=2)
			{
				if((team[i]==a&&team[i+1]==b))
				{
					if(pp==cnt)
					{
						printf("Final!\n");
					}
					else
						printf("%d\n",pp);
					goto loop;
				}
				if(team[i]==a)
					team[i+1]=1000;
				else if(team[i+1]==a)
					team[i]=1000;
				else if(team[i]==b)
					team[i+1]=1000;
				else if(team[i+1]==b)
					team[i]=1000;
				else
					team[i+1]=1000;
			}
			sort(team,team+n+1);
		}
loop:	int ok=1;
	}
	return 0;
}

