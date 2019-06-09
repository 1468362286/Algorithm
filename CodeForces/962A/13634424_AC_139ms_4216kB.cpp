#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
int a[200010];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{	
		ll sum=0;
		int ans=0;
		for( i = 1 ; i <= n ; i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		ll num=0;
		for( i = 1 ; i <= n ; i++)
		{
			num+=a[i];
			if(num>=(1.0*sum)/2)
			{
				ans = i;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}