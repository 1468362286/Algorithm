#include <stdio.h>
#include <utility>
using namespace std;
const int maxn = 1010;
pair<double,double> v[maxn],tmp;
int vist[maxn];
int id[]={0,3,1,2};
int main()
{
	//freopen("in.txt","r",stdin);
	double k[4];
	int n,i,j;
	double x;
	while(~scanf("%d",&n))
	{
		int gg,cnt;
		int flag=0;
		int op = 0;
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%lf",&x);
			v[i].first=i*1.0;
			v[i].second=x;
		}
		k[1]=v[2].second-v[1].second;
		k[2]=v[3].second-v[2].second;
		k[3]=(v[3].second-v[1].second)/2;
		if(k[1]==k[2])
			op = 1;
		for( i = 1 ; i <= 3 ; i++)
		{
			gg=0;
			memset(vist,0,sizeof(vist));
			if(i==1)
			{
				vist[1]=vist[2]=1;
			}
			else if(i==2)
			{
				vist[2]=vist[3]=1;
			}
			else if(i==3)
			{
				vist[1]=vist[3]=1;
			}
			for( j = 4 ; j <= n ; j++)
			{
				if((v[j].second-v[i].second)/(v[j].first-v[i].first)==k[i])
				{
					vist[j]=1;
				}
			}
			cnt = 0;
			for( j = 4 ; j <= n ; j++)
			{
				if(!vist[j]&&!op)
				{
					if((v[j].second-v[id[i]].second)/(v[j].first-v[id[i]].first)!=k[i])
					{
						gg=1;
						break;
					//	goto loop;
					}
				}
				else if(!vist[j]&&op)
				{
					cnt++;
					if(cnt==1)
					{
						tmp.first=j;
						tmp.second=v[j].second;
						continue;
					}
					if((v[j].second-tmp.second)/(v[j].first-tmp.first)!=k[i])
					{
						gg=1;
						break;
					}	
				}
			}
			/*
			if(gg==0&&k[1]==k[2]&&k[1]==k[3])
			{
				gg=1;
			}
			*/
			if(op&&!cnt)
				gg=1;
			if(gg==0)
			{
				flag=1;
				break;
			}
		}
//loop:		
			if(!flag)
				printf("No\n");
			else
				printf("Yes\n");
	}
	return 0;
}