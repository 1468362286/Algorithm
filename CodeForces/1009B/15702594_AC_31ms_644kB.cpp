#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	string s;
	while(cin>>s)
	{
		int flag=0,cnt0=0,cnt1=0;
		string tmp="";
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]=='0'&&!flag)
				cnt0++;
			else if(s[i]=='0'&&flag)
			{
				tmp+=s[i];
			}
			else if(s[i]=='1')
				cnt1++;
			else if(s[i]=='2'&&!flag)
			{
				flag=1;
				tmp+=s[i];
			}
			else if(s[i]=='2'&&flag)
			{
				tmp+=s[i];
			}
		}
		for( i = 0 ; i < cnt0 ; i++)
			cout<<"0";
		for( i = 0 ; i < cnt1 ; i++)
			cout<<"1";
		if(tmp.size()>0)
			cout<<tmp;
		cout<<endl;
	}
	return 0;
}