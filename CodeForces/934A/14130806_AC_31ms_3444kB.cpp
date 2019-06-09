#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef _int64 ll;
const ll inf=0x7fffffff;
ll a[110];
ll b[100];
ll max(ll a,ll b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	while(cin>>n>>m)
	{
		for( i = 0 ; i < n ; i++)scanf("%I64d",&a[i]);
		for( j = 0 ; j < m ; j++)scanf("%I64d",&b[j]);
		int ansi;
		ll ans;
		ll maxi=-inf*inf;
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < m ; j++)
			{
				ans=a[i]*b[j];
				if(maxi<ans)
				{
					maxi=ans;
					ansi=i;
				}
			}
		maxi=-inf*inf;
		for( i = 0 ; i < n ; i++)
			if(i!=ansi)
			for( j = 0 ; j < m ; j++)
			{
				ans=a[i]*b[j];
				maxi=max(maxi,ans);
			}
		printf("%I64d\n",maxi);
	}
	return 0;
}