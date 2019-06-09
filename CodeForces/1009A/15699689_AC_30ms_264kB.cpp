#include <iostream>
#include <string>
using namespace std;
const int maxn=1010;
int a[maxn],c[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j;
	while(cin>>n>>m)
	{
		for( i = 0 ; i < n ; i++)
			cin>>c[i];
		for( i = 0 ; i < m ; i++)
			cin>>a[i];
		int ans=0;
		for( i = 0,j=0 ; i < n ; i++)
		{
			if(a[j]>=c[i])
			{
				ans++;
				j++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}