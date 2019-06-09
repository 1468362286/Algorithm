#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int a[110];
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n/2 ; i++)
			cin>>a[i];
		sort(a,a+n/2);
		int ans1=0;
		int ans2=0;
		int x1=1;
		int x2=2;
		for( i = 0 ; i < n/2 ; i++)
		{
			ans1+=abs(a[i]-x1);
			x1+=2;
			ans2+=abs(a[i]-x2);
			x2+=2;
		}
		int ans=min(ans1,ans2);
		cout<<ans<<endl;
	}
	return 0;
}