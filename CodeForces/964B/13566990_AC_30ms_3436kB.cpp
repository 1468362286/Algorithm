#include <iostream>
#include <string>
using namespace std;
int a[1010];

int main()
{
	int n,A,B,C,T,i;
	while(cin>>n>>A>>B>>C>>T)
	{
		int ans=0;
		for( i = 1 ; i <= n ; i++)
		{
			cin>>a[i];
		}
		ans=n*A;
		if(B<C)
		{
			for( i = 1 ; i <= n ; i++)
				ans+=(C-B)*(T-a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}