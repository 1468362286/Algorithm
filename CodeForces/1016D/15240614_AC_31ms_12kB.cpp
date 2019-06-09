#include <iostream>
#include <string>
using namespace std;
const int maxn = 110;
int a[maxn],b[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j;
	while(cin>>n>>m)
	{
		int suma=0,sumb=0;
		for( i = 1 ; i <= n ; i++)
			cin>>a[i],suma^=a[i];
		for( i = 1 ; i <= m ; i++)
			cin>>b[i],sumb^=b[i];
		if(suma!=sumb)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<(sumb^b[1]^a[1])<<" ";
			for( i = 2 ; i <= m ; i++)
				cout<<b[i]<<" ";
			cout<<endl;
			for( i = 2 ; i <= n ; i++)
			{
				cout<<a[i]<<" ";
				for( j = 2 ; j <= m ; j++)
					cout<<"0"<<" ";
				cout<<endl;
			}
		}
	}
	return 0;
}