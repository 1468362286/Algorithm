#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,l,r;
	string a,b;
	while(cin>>n)
	{
		cin>>a>>b;
		int ans=0;
		for( i = 0 ; i < n/2 ; i++)
		{
			l=i,r=n-i-1;
			if((a[l]==a[r]&&b[l]==b[r])||(a[l]==b[l]&&a[r]==b[r])||(a[l]==b[r]&&a[r]==b[l]))
				continue;
			else if(a[l]==b[l]||a[l]==b[r]||a[r]==b[l]||a[r]==b[r]||b[l]==b[r])
				ans++;
			else 
				ans+=2;
		}
		if(n%2&&a[n/2]!=b[n/2])ans++;
		cout<<ans<<endl;
	}
	return 0;
}
