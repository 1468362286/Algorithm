#include <iostream>
#include <string>
using namespace std;
const int maxn = 55;
int a[maxn],b[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		int sum1=0,sum2=0,sum=0;
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		for( i = 0 ; i < n ; i++)
			cin>>b[i];
		for( i = 0 ; i < n ; i++)
			if(a[i]>=b[i])sum1+=(a[i]-b[i]);
			else sum2+=(b[i]-a[i]);
		if(sum1>=sum2)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}