#include <iostream>
#include <string>
using namespace std;
const int maxn = 100010;
int t[maxn],l[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,L,a,i;
	while(cin>>n>>L>>a)
	{
		for( i = 0 ; i < n ; i++)
			cin>>t[i]>>l[i];
		int ans=0;
		for( i = 0 ; i < n ; i++)
		{
			if(i==0)
			{
				if(t[i]!=0)
				{
					ans+=t[i]/a;
				}
			}
			else
			{
				ans+=(t[i]-(t[i-1]+l[i-1]))/a;
			}
		}
		ans+=(L-t[n-1]-l[n-1])/a;
		
		cout<<ans<<endl;
	}
	return 0;
}