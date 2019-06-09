#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int T,i;
	string s;
	vector<int>a,b,c;
	cin>>T;
	while(T--)
	{
		cin>>s;
		a.clear(),b.clear(),c.clear();
		
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				a.push_back(i);
			}
			else if(s[i]>='a'&&s[i]<='z')
			{
				b.push_back(i);
			}
			else if(s[i]>='A'&&s[i]<='Z')
			{
				c.push_back(i);
			}
		}
		if(a.size()==0)
		{
			if(b.size()>=2)
			{
				s[b[b.size()-1]]='1';
				b.pop_back();
			}
			else 
			{
				s[c[c.size()-1]]='1';
				c.pop_back();
			}
		}
		if(b.size()==0)
		{
			if(a.size()>=2)
			{
				s[a[a.size()-1]]='a';
				a.pop_back();
			}
			else
			{
				s[c[c.size()-1]]='a';
				c.pop_back();
			}
		}
		if(c.size()==0)
		{
			if(a.size()>=2)
			{
				s[a[a.size()-1]]='A';
				a.pop_back();
			}
			else
			{
				s[b[b.size()-1]]='A';
				b.pop_back();
			}
		}
		
		cout<<s<<endl;
	}
	return 0;
}