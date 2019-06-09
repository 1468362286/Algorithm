#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

map<string,int> mymap;
string change(string x)
{
	string tmp;
	int flag = 0;
	for(int i = 0 ; i < x.size() ; i++)
	{
		char c=(x[i]-'0')%2+'0';
		if(c!='0')
			flag = 1;
		if(flag)
			tmp+=c;
	}
	if(!flag) tmp="0";
	return tmp;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int T,i;
	string s,x,ch;
	cin>>T;
	while(T--)
	{
		cin>>s>>x;
		if(s=="+")
		{
			ch = change(x);
			mymap[ch]++;
		}
		else if(s=="-")
		{
			ch = change(x);
			mymap[ch]--;			
		}
		else if(s=="?")
		{
			int flag = 0;
			for(int i = 0 ; i < x.size() ; i++)
			{
				if(x[i]!='0')
				{
					flag = 1;
					ch = x.substr(i,x.size());
					break;
				}
			}
			if(!flag) ch="0";
			cout<<mymap[ch]<<endl;
		}
	}
	return 0;
}