#include <iostream>
#include <string>
using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	string s;
	int i;
	while(cin>>s)
	{
		int cnt=0;
		int ans=0;
		int l=0,r=0;
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]=='['&&cnt==0)
				cnt++;
			else if(s[i]==':'&&cnt==1)
			{
				l=i;
				break;
			}
		}
		cnt=0;
		for( i = s.size()-1 ; i >= 0 ; i--)
		{
			if(s[i]==']'&&cnt==0)
				cnt++;
			else if(s[i]==':'&&cnt==1)
			{
				r=i;
				break;
			}
		}
		if(l<r&&l>=1&&r<=s.size()-2)
		{
			for( i = l+1 ; i < r ; i++)
			{
				if(s[i]=='|')
					ans++;
			}
			cout<<4+ans<<endl;
		}	
		else cout<<-1<<endl;
	}
	return 0;
}