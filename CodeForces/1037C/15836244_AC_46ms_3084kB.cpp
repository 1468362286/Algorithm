#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	string s,t;
	while(cin>>n)
	{
		cin>>s>>t;
		int ans=0;
		for( i = 0 ; i < n ; i++)
		{
			if(s[i]!=t[i])
			{
				if(s[i+1]!=t[i+1]&&(s[i]!=s[i+1])&&(i!=n-1))
				{
					ans++;
					i++;
				}
				else
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}