#include <iostream>
#include <string>
using namespace std;
const int maxn = 100010;
int a[maxn],b[maxn],pre_sum[maxn];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	int n,k,i,j;
	while(cin>>n>>k)
	{
		int sum=0;
		memset(pre_sum,0,sizeof(pre_sum));
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		for( i = 1 ; i <= n ; i++)
		{
			cin>>b[i];
			if(b[i])sum+=a[i],a[i]=0;
		}
		int ans=0;
		for( i = 1 ; i <= n ; i++)
		{
			pre_sum[i]=pre_sum[i-1]+a[i];
		}
		for( i = 1 ; i <= n-k+1 ; i++)
			ans=max(ans,pre_sum[i+k-1]-pre_sum[i-1]);
		cout<<sum+ans<<endl;
	}
	return 0;
}
