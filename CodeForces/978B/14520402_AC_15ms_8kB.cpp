#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	string s;
	while(cin>>n)
	{
		cin>>s;
		int cnt=0;
		int ans=0;
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(s[i]=='x')
			{
				cnt++;
			}
			else
			{
				if(cnt>=3)
					ans+=(cnt-2);
				cnt=0;
			}
		}
		if(cnt>=3)
			ans+=(cnt-2);
		cout<<ans<<endl;
	}
	return 0;
}