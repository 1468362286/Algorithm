#include <iostream>
#include <string>
using namespace std;
string a[2010];
int map[2010];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,i,j;
	while(cin>>n>>m)
	{
		memset(map,0,sizeof(map));
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
			for( j = 0 ; j < m ; j++)
			{
				map[j]+=a[i][j]-'0';
			}
		}
		int flag=0;
		for( i = 0 ; i < n ; i++)
		{
			int cnt=0;
			for( j = 0 ; j < m ; j++)
			{
				if(map[j]-(a[i][j]-'0')>0)
					cnt++;
			}
			if(cnt==m)
			{
				flag=1;
				break;
			}
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}