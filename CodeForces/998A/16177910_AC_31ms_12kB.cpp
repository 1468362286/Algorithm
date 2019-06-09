#include <iostream>
#include <string>
using namespace std;
int a[15];
int pre_sum[15];
int main()
{
	int n,i;
	while(cin>>n)
	{
		int sum=0;
		for( i = 1 ; i <= n ; i++)
			cin>>a[i],pre_sum[i] = pre_sum[i-1]+a[i];
		sum=pre_sum[n];
		if(n==1)
		{
			cout<<"-1"<<endl;
			continue;
		}
		int ans=0;
		for( i = 1 ; i <= n-1 ; i++)
		{
			if(sum-pre_sum[i]!=pre_sum[i])
			{
				ans=i;
				break;
			}
		}
		if(ans==0)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<ans<<endl;
			for( i = 1 ; i <= ans ; i++)
			{
				cout<<i<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}