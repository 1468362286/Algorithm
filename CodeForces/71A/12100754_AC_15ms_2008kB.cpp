#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s;
		if(s.size()>10)
			cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
		else
			cout<<s<<endl;
	}
	return 0;
}
