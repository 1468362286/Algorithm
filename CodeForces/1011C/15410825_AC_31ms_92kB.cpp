#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 10005;
int n,m,a[maxn],b[maxn];

bool check(double x)
{
	double sum=m+x;
	if(sum>m)
		sum-=sum/a[1];
	else
		return 0;
	for(int i = 2 ; i <= n ; i++)
	{
		if(sum>m)
			sum-=sum/a[i];
		else
			return 0;
		if(sum>m)
			sum-=sum/b[i];

		else
			return 0;
	}
	if(sum>m)
		sum-=sum/b[1];
	else
		return 0;
	if(sum>=m)
		return 1;
	else
		return 0;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(cin>>n>>m)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		for( i = 1 ; i <= n ; i++)
			cin>>b[i];
		double l=0,r=1000000010,mid,ans=-1;
		int flag=0;
		while(r-l>=0.000001)
		{
			mid=(l+r)/2.0;
			if(check(mid))
			{
				ans=mid;
				r=mid;
				flag=1;
			}
			else
				l=mid;
		}
		if(!flag)cout<<-1;
		else
			printf("%.10f",ans);
	}
	return 0;
}