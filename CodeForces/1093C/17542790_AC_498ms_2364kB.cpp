#include <iostream>
#include <string>
#include <string.h>
using namespace std;
typedef long long ll;
const int maxn = 200010;
const ll inf=1e18+1;
ll b[maxn/2];
ll a[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		for( i = 1 ; i <= n/2 ; i++)
			cin>>b[i];
		a[n+1]=inf;
		for( i = 1 ; i <= n/2 ; i++)
		{
			a[i]=a[i-1];
			a[n-i+1]=b[i]-a[i];
			if(a[n-i+1]>a[n-i+2])
			{
				a[n-i+1]=a[n-i+2];
				a[i]=b[i]-a[n-i+1];
			}
		}
		for( i = 1 ; i <= n ; i++)
			cout<<a[i]<<" ";
		printf("\n");
	}
	return 0;
}