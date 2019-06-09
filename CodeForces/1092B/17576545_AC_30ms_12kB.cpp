#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
typedef _int64 ll;
int a[110];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		int ans=0;
		for( i = 1 ; i < n ; i+=2)
		{
			ans+=a[i]-a[i-1];
		}
		cout<<ans<<endl;
	}
	return 0;
}