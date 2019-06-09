#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int i;
	while(cin>>s)
	{
		string tmp="";
		for( i = s.size()-1 ; i >= 0 ; i--)
			tmp+=s[i];
		cout<<s+tmp<<endl;
	}
	return 0;
}