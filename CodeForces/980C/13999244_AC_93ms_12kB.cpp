#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
inline int max(int a,int b){return a>b?a:b;}
int a[260];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i,j;
	while(cin>>n>>k)
	{
		for( i = 0 ; i < 256 ; i++)
			a[i]=-1;
		while(n--)
		{
			int x;
			cin>>x;
			if(a[x]==-1)
			{
				for( i = max(0,x-k+1) ; i <= x ; i++)
				{
					if(a[i]==-1||a[i]==i)
					{
						for( j = i ; j <= x ; j++)
							a[j]=i;
						break;
					}
				}
			}
			printf("%d ",a[x]);
		}
	}
	return 0;
}