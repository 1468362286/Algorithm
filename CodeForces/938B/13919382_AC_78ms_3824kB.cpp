#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int a[100010];
const int z = 1000000;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
		}
		int ans=0x3f3f3f3f;
		for( i = 0 ; i < n-1 ; i++)
		{
			int tmp = max(abs(a[i]-1),abs(z-a[i+1]));
			ans=min(tmp,ans);
		}
		ans=min(abs(z-a[0]),min(ans,abs(a[n-1]-1)));
		cout<<ans<<endl;
	}
	return 0;
}