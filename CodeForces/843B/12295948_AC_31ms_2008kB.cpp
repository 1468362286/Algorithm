#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,start,x,k,i,value,next,ans,pos;
	srand(time(NULL));
	while(cin>>n>>start>>x)
	{
		ans = -1;
		pos = start;
		for( i = 0 ; i < 1000 ; i++)
		{
			k = (rand()*rand())%n+1;
			printf("? %d\n",k);
			fflush(stdout);
			scanf("%d%d",&value,&next);
			if(value<x)
			{
				if(x-ans>x-value)
				{
					ans = value;
					pos = next;
				}
			}
		}
		int flag=0;
		int cnt=0;
		while(ans<x)
		{
			if(pos==-1)
			{
				flag=1;
				break;
			}
			printf("? %d\n",pos);
			fflush(stdout);
			scanf("%d%d",&value,&next);
			ans=value;
			pos=next;
			cnt++;
			if(cnt==998)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		printf("! %d\n",ans);
		else
			printf("! -1\n");
		fflush(stdout);
	}
	return 0;
}