#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef _int64 ll;
int a[100010];
int main()
{
	int n,m,x,y,i,ans;
	while(cin>>n>>m)
	{
		ll sum=0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>x>>y;
			a[i] = x-y;
			sum+=x;
		}
		sort(a,a+n);
		int flag=0;
		if(sum<=m)
		{
			cout<<"0"<<endl;
			continue;
		}
		for( i = n-1 ; i >= 0 ; i--)
		{
			sum-=a[i];
			if(sum<=m)
			{
				flag=1;
				ans=n-i;
				break;
			}
		}
		if(flag)cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}