#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int maxn = 100010;
int a[maxn],b[maxn];
int pre_sum1[maxn],pre_sum2[maxn];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,i,j;
	while(cin>>n>>m)
	{
		//memset(pre_sum1,0,sizeof(pre_sum1));
		//memset(pre_sum2,0,sizeof(pre_sum2));
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		for( i = 1 ; i <= m ; i++)
			cin>>b[i];
		int sum1=a[1];
		int sum2=b[1];
		int cnt=0;
		i=j=1;
		while(i<=n&&j<=m)
		{
			if(sum1<sum2)
			{
				i++;
				sum1+=a[i];
			}
			if(sum1>sum2)
			{
				j++;
				sum2+=b[j];
			}
			if(sum1==sum2)
			{
				cnt++;
				i++;
				j++;
				sum1=a[i];
				sum2=b[j];
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}