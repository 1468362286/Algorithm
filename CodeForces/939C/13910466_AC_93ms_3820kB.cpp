#include <iostream>
#include <string>
using namespace std;
int a[100010];
int min(int a,int b){return a>b?b:a;}
int main()
{
	int n,i,s,f;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		cin>>s>>f;
		int ans=n;
		int inter=f-s;
		int sum=0,mx=0,mark=1;
		for( i = 1; i <= inter ; ++i)
			sum+=a[i];
		mx=sum;
		ans=s;
		for(int beg=2;beg<=n;++beg)
		{
			int end=beg+inter-1;
			end=end>n?end-n:end;
			sum-=a[beg-1];
			sum+=a[end];
			int t=beg-1;
			if(sum>mx)
			{
				mx=sum;
				ans=s-t<=0?s-t+n:s-t;
			}
			else if(sum==mx)
			{
				ans=min(ans,s-t<=0?s-t+n:s-t);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}