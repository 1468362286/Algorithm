#include <stdio.h>
#include <vector>
using namespace std;
const int maxn = 110;
vector<int>ans;
vector<int>floor1[maxn];
/*
template<typename T>
static T max(T a,T b)
{
	return a>b?a:b;
}
*/
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,flag,x,y,pp,tmp;
	while(~scanf("%d%d",&n,&m))
	{
		int maxi = 0;
		for( i = 1 ; i <= n ; i++)
			floor1[i].clear();
		ans.clear();
		for( i = 0 ; i < m ; i++)
		{
			scanf("%d%d",&x,&y);
			floor1[y].push_back(x);
			maxi = max(maxi,y);
		}
		for( i = 1 ; i <= 100 ; i++)
		{
			flag = 0;
			for( j = 1 ; j <= maxi ; j++)
			{
				int len = floor1[j].size();
				for( k = 0 ; k < len ; k++)
				{
					if((1+i*(j-1))>floor1[j][k]||floor1[j][k]>i*j)
					{
						flag=1;
						break;
					}
				}
				if(flag)
					break;
			}
			if(!flag)
				ans.push_back(i);
		}
		flag=0;
		if(ans.size()>=1)
		{
			if(n%ans[0]==0)
				pp = n/ans[0];
			else
				pp = n/ans[0]+1;
			for( i = 1 ; i < ans.size() ; i++)
			{
				if(n%ans[i]==0)
					tmp = n/ans[i];
				else
					tmp = n/ans[i]+1;
				if(tmp!=pp)
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			printf("%d\n",pp);
			else
				printf("-1\n");
		}
		else
		{
			printf("-1\n");
		}

	}
	return 0;
}