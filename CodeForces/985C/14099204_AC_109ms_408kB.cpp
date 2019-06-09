#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef _int64 ll;
int a[100010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,l,i;
	while(cin>>n>>k>>l)
	{
		for( i = 0 ; i < n*k ; i++)
			cin>>a[i];
		sort(a,a+n*k);
		if(a[n-1]-a[0]>l)
		{
			cout<<0<<endl;
		}
		else
		{
			ll rn = lower_bound(a,a+n*k,a[0]+1+l)-a;
			ll cnt=rn-n;
			ll ln=0,res=0;
			for( i = 0 ; i < n ; i++)
			{
				res+=a[ln];
				if(cnt>=k-1)
				{
					cnt-=k-1;
					ln+=k-1;
				}
				else if(cnt)
				{
					ln+=cnt;
					cnt=0;
				}
				ln++;
			}
			printf("%I64d\n",res);
		}
	}
	return 0;
}