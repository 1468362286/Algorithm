#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[110];
int round(double x){return int(x+0.5);}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		int sum=0;
		for( i = 0 ; i < n ; i++)
			cin>>a[i],sum+=a[i];
		if(round(1.0*sum/n)==5)
		{
			cout<<"0"<<endl;
		}
		else
		{
			int ans;
			sort(a,a+n);
			for( i = 0 ; i < n ; i++)
			{
				sum = sum-a[i]+5;
				if(round(1.0*sum/n)==5)
				{
					ans=i+1;
					break;
				}
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}