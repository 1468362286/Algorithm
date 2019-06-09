#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int T,n;
	string s;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cin>>s;
		int flag=0;
		for(int i = 0 ; i < n ; i++)
		{
			if(s[i]!=s[n-i-1])
			{
				if(abs(s[i]-s[n-i-1])!=2)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}