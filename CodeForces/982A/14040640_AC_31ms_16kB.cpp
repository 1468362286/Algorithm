#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	string s;
	while(cin>>n)
	{
		cin>>s;
		int flag=0;
		if(n==1)
		{
			if(s[0]=='1')
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
			continue;
		}
		else if(n==2)
		{
			if((s[0]=='0'&&s[1]=='1')||(s[0]=='1'&&s[1]=='0'))
				cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
			continue;
		}
		s='0'+s+'0';
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(s[i]=='1')
			{
				if(s[i-1]=='1'||s[i+1]=='1')
				{
					flag=1;
					break;
				}
			}
			else
			{
				if(s[i-1]=='0'&&s[i+1]=='0')
				{
					flag=1;
					break;
				}
			}
		}
		if(flag)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}