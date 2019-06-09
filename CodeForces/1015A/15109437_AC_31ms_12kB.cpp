#include <iostream>
#include <string>
using namespace std;
int vist[110];
int main()
{
	int n,m,x,y,i,j;
	while(cin>>n>>m)
	{
		memset(vist,0,sizeof(vist));
		for( i = 0 ; i < n ; i++)
		{
			cin>>x>>y;
			for( j = x ; j <= y ; j++)
			{
				vist[j]=1;
			}
		}	
		int ans=0;
		for( i = 1 ; i <= m ; i++)
		{
			if(!vist[i])
				ans++;
		}
		cout<<ans<<endl;
		for( i = 1 ; i <= m ; i++)
		{
			if(!vist[i])
			cout<<i<<" ";
		}	
		cout<<endl;
	}
	return 0;
}	