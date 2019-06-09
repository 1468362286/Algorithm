#include <iostream>
#include <string>
using namespace std;
const int maxn = 110;
int a[maxn],b[maxn];
int sum1[10],sum2[10],sum[10];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));
		memset(sum,0,sizeof(sum));
		for( i = 0 ; i < n ; i++)
			cin>>a[i],sum1[a[i]]++;
		for( i = 0 ; i < n ; i++)
			cin>>b[i],sum2[b[i]]++;
		for( i = 1 ; i <= 5 ; i++)
		{
			sum[i]=sum1[i]+sum2[i];
		}
		int flag=0;
		int ans=0;
		for( i = 1 ; i <= 5 ; i++)
		{
			if(sum[i]%2!=0)
			{
				flag=1;
				break;
			}
			else if(sum[i]!=0)
			{
				ans+=abs(sum[i]/2-sum1[i]);
			}
		}
		if(flag)cout<<"-1"<<endl;
		else cout<<ans/2<<endl;
	}
	return 0;
}