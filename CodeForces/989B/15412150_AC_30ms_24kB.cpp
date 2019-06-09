#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,p,i;
	string s;
	while(cin>>n>>p)
	{
		cin>>s;
		int flag=0;
	//	int cnt=0;
		for( i = 0 ; i < n-p ; i++)
		{
			if(s[i]=='.'&&s[i+p]=='.')
			{
				s[i]='0',s[i+p]='1';
				flag=1;
			}
			else if(s[i]=='.')
			{
				if(s[i+p]=='0')
					s[i]='1';
				else if(s[i+p]=='1')
					s[i]='0';
				flag=1;
			}
			else if(s[i+p]=='.')
			{
				if(s[i]=='0')
					s[i+p]='1';
				else if(s[i]=='1')
					s[i+p]='0';
				flag=1;
			}
			else 
			{
				if(s[i]!=s[i+p])
				{
					flag=1;
				}
			}
		}
		for( i = n-p ; i < s.size() ; i++)
			if(s[i]=='.')
				s[i]='0';
		if(!flag)cout<<"No"<<endl;
		else cout<<s<<endl;
	}
	return 0;
}